# 📱 Instagram Portal WiFi Captive

<div align="center">

![ESP8266](https://img.shields.io/badge/ESP8266-v3.1.2-blue.svg)
![Arduino](https://img.shields.io/badge/Arduino-IDE%202.0+-green.svg)
![License](https://img.shields.io/badge/License-Educational-red.svg)
![Version](https://img.shields.io/badge/Version-1.0.0-orange.svg)
![Build](https://img.shields.io/badge/Build-Passing-success.svg)
![Security](https://img.shields.io/badge/Security-Tested-success.svg)
![ESP](https://img.shields.io/badge/ESP-Supported-blue.svg)
![WiFi](https://img.shields.io/badge/WiFi-Compatible-brightgreen.svg)

![NodeMCU](https://shields.io/badge/NodeMCU-ESP8266-blue?logo=arduino&style=for-the-badge)
![Portal](https://shields.io/badge/Captive-Portal-red?logo=wifi&style=for-the-badge)
![Instagram](https://shields.io/badge/Instagram-Clone-purple?logo=instagram&style=for-the-badge)

</div>

## 📝 وصف المشروع
نظام متقدم يعتمد على ESP8266 لإنشاء نقطة وصول WiFi مع بوابة تسجيل دخول تحاكي واجهة Instagram. مثالي للتعليم وفهم كيفية عمل بوابات الشبكات اللاسلكية.

## ✨ المميزات الرئيسية
- 🎯 واجهة تسجيل دخول مطابقة تماماً لـ Instagram
- 🌐 توجيه تلقائي للبوابة
- 💾 نظام تخزين آمن للبيانات
- 🔐 لوحة تحكم محمية بكلمة مرور
- 📱 تصميم متجاوب مع جميع الأجهزة
- ⚡ اتصال سريع وموثوق
- 🔄 بث تلقائي لشبكة WiFi
- 📊 مراقبة الاتصالات في الوقت الفعلي

## 🛠️ متطلبات الأجهزة
- لوحة تطوير ESP8266 (الموديلات الموصى بها):
  - NodeMCU ESP8266
  - Wemos D1 Mini
  - ESP-12E Module
- كابل USB صغير للبرمجة
- مصدر طاقة (USB/بطارية)

## 💻 متطلبات البرامج
### الأدوات المطلوبة
- Arduino IDE (يوصى بالإصدار 2.0+)
- حزمة ESP8266 Board
- متصفح ويب

### المكتبات المطلوبة
```cpp
#include <ESP8266WiFi.h>      // وظائف WiFi
#include <DNSServer.h>        // خادم DNS للبوابة
#include <ESP8266WebServer.h> // وظائف خادم الويب
```

## 📥 دليل التثبيت
1. **إعداد Arduino IDE**
   ```bash
   # تثبيت حزمة ESP8266
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

2. **المكتبات المطلوبة**
   - انتقل إلى Tools > Manage Libraries
   - قم بتثبيت جميع المكتبات المذكورة أعلاه

3. **تكوين ESP8266**
   - Board: "NodeMCU 1.0 (ESP-12E Module)"
   - Upload Speed: "115200"
   - CPU Frequency: "80 MHz"
   - Flash Size: "4MB (FS:2MB OTA:~1019KB)"

## 🚀 البدء السريع
1. استنسخ المستودع
   ```bash
   git clone https://github.com/yourusername/instagram_portal.git
   ```
2. افتح `instagram_portal.ino` في Arduino IDE
3. قم بتكوين الإعدادات في الكود:
   ```cpp
   const char* ssid = "Free WiFi";            // تغيير اسم الشبكة
   const char* admin_password = "your_pass";   // تغيير كلمة مرور المشرف
   ```
4. ارفع الكود إلى ESP8266
5. شغل الجهاز

## 📱 تعليمات الاستخدام
1. **الإعداد الأولي**
   - قم بتشغيل ESP8266
   - ابحث عن شبكة "Free WiFi"
   - اتصل بالشبكة

2. **نقاط الوصول**
   - البوابة الرئيسية: `http://192.168.4.1`
   - لوحة المشرف: `http://192.168.4.1/admin`
   - كلمة المرور الافتراضية: `zaid46`

3. **ميزات لوحة المشرف**
   - عرض البيانات المسجلة
   - مراقبة الاتصالات النشطة
   - إحصائيات النظام
   - سجلات في الوقت الفعلي

## ⚙️ خيارات التكوين
```cpp
// تكوين الشبكة
const char* ssid = "Free WiFi";              // اسم شبكة WiFi
const char* admin_password = "zaid46";       // كلمة مرور لوحة المشرف
const IPAddress apIP(192, 168, 4, 1);       // عنوان IP للبوابة
const byte DNS_PORT = 53;                    // منفذ DNS

// تكوين التخزين
#define MAX_CREDENTIALS 50                   // الحد الأقصى للإدخالات المخزنة
```

## 🔍 استكشاف الأخطاء وإصلاحها
المشاكل الشائعة والحلول:

| المشكلة | الحل |
|---------|------|
| الجهاز لا يبث | تحقق من مصدر الطاقة |
| لا يمكن الوصول للوحة المشرف | تحقق من عنوان IP |
| البوابة لا تعيد التوجيه | امسح ذاكرة التخزين المؤقت للمتصفح |
| الاتصال ينقطع | تحقق من طاقة ESP8266 |

## 🛡️ تنبيه أمني
هذه الأداة مصممة **لأغراض تعليمية فقط**. استخدام هذه الأداة لمهاجمة الأهداف دون موافقة مسبقة غير قانوني. المطورون لا يتحملون أي مسؤولية عن أي إساءة استخدام أو ضرر ناتج عن هذا البرنامج.

## 🤝 المساهمة
نرحب بالمساهمات! لا تتردد في تقديم طلب سحب.

## 📄 الترخيص
هذا المشروع مرخص للأغراض التعليمية فقط. غير مخصص للاستخدام التجاري أو الضار.

## ⚠️ إخلاء المسؤولية
هذا المشروع لأغراض تعليمية فقط. المطورون لا يؤيدون أو يشجعون أي استخدام ضار لهذا الكود.

## 📧 الاتصال
للاستفسارات التعليمية والتطويرية فقط:
- أنشئ مشكلة في هذا المستودع
- قدم طلب سحب

---
<div align="center">
صنع بـ ❤️ لأغراض تعليمية فقط
</div>
