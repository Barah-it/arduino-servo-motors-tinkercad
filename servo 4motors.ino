/*
  مهمة: التحكم في 4 محركات سيرفو (Servo Motors)
  الحركة 1: Sweep (يمين ويسار) لمدة ثانيتين
  الحركة 2: التوقف والثبات عند زاوية 90 درجة

  التوصيل المقترح على Tinkercad:
  - Servo 1 -> Pin 3
  - Servo 2 -> Pin 5
  - Servo 3 -> Pin 6
  - Servo 4 -> Pin 9
  - كل سيرفو: السلك البرتقالي (Signal) على البن، الأحمر (VCC) على 5V، الأسود/البني (GND) على GND
*/

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int pinServo1 = 3;
const int pinServo2 = 5;
const int pinServo3 = 6;
const int pinServo4 = 9;

void setup() {
  // ربط كل سيرفو بالبن الخاص فيه
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);

  // ---- الحركة الأولى: Sweep لمدة ثانيتين فقط ----
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    // تحرك من 0 إلى 180 درجة
    for (int angle = 0; angle <= 180; angle += 5) {
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
      servo4.write(angle);
      delay(15);
      if (millis() - startTime >= 2000) break;
    }
    if (millis() - startTime >= 2000) break;

    // تحرك من 180 إلى 0 درجة
    for (int angle = 180; angle >= 0; angle -= 5) {
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
      servo4.write(angle);
      delay(15);
      if (millis() - startTime >= 2000) break;
    }
  }

  // ---- الحركة الثانية: التوقف والثبات عند 90 درجة ----
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  // لا يوجد شيء هنا لأن المحركات تثبت عند 90 درجة بعد setup()
  // إذا أردت تكرار الدورة بالكامل من جديد، انقل الكود من setup() إلى هنا
}
