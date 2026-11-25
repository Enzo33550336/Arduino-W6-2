const int pinA = 16;   // กำหนดขา GPIO 16 ให้ชื่อ pinA = เซกเมนต์ a (ขีดบนสุด) ; const = ค่าคงที่ เปลี่ยนไม่ได้
const int pinB = 17;   // ขา 17 = เซกเมนต์ b (ขีดขวาบน)
const int pinC = 18;   // ขา 18 = เซกเมนต์ c (ขีดขวาล่าง)
const int pinD = 19;   // ขา 19 = เซกเมนต์ d (ขีดล่างสุด)
const int pinE = 21;   // ขา 21 = เซกเมนต์ e (ขีดซ้ายล่าง)
const int pinF = 22;   // ขา 22 = เซกเมนต์ f (ขีดซ้ายบน)
const int pinG = 23;   // ขา 23 = เซกเมนต์ g (ขีดกลาง)
const int pinDP = 25;  // ขา 25 = จุดทศนิยม (DP) ในโค้ดนี้ประกาศไว้แต่ไม่ได้ใช้แสดงผล


void setup() {                 // ฟังก์ชัน setup ทำงาน "ครั้งเดียว" ตอนเปิดบอร์ด/รีเซ็ต
  Serial.begin(115200);        // เริ่มสื่อสารผ่าน Serial ที่ความเร็ว 115200 บอด (Serial Monitor ต้องตั้งให้ตรงกัน)
  Serial.setTimeout(50);     // ลดเวลารอ parseInt จาก 1000 ms เหลือ 50 ms
  pinMode(pinA, OUTPUT);       // ตั้งขา pinA เป็นโหมด OUTPUT (ส่งไฟออกไปควบคุม LED)
  pinMode(pinB, OUTPUT);       // ขา B ตั้งเป็น OUTPUT เช่นกัน (บรรทัดถัดไปทำเหมือนกันจนถึง pinDP)
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  Serial.println("Type a digit 0-9 and press Enter");   // พิมพ์ข้อความแนะนำให้ผู้ใช้พิมพ์เลข 0-9 แล้วกด Enter (println = พิมพ์แล้วขึ้นบรรทัดใหม่)
}


void loop() {                  // ฟังก์ชัน loop ทำงาน "วนซ้ำตลอดเวลา" หลัง setup จบ
  if (Serial.available() > 0) {   // เช็คว่ามีข้อมูลเข้ามาใน Serial buffer ไหม (จำนวน byte ที่ค้างอยู่ > 0)
    int n = Serial.parseInt();                // อ่านเลขทั้งก้อน เช่น พิมพ์ 2 ได้ 2
    while (Serial.available() > 0) Serial.read();   // ทิ้งตัวขึ้นบรรทัดใหม่ที่ค้างอยู่


    Serial.print("Received: ");   // พิมพ์คำว่า Received: (print = ไม่ขึ้นบรรทัดใหม่)
    Serial.println(n);            // พิมพ์ค่าเลขที่ได้รับ แล้วขึ้นบรรทัดใหม่


    if (n == 2) {                             // ตัวอย่างแสดงเฉพาะเลข 2
    digitalWrite(pinA, HIGH);     // HIGH = จ่ายไฟ = LED เซกเมนต์ a ติด (ใช้กับ 7-segment แบบ Common Cathode)
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, LOW);    // LOW = ไม่จ่ายไฟ = LED เซกเมนต์ c ดับ
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, LOW);    // f ดับ
      digitalWrite(pinG, HIGH);   // g ติด  -> a,b,d,e,g ติด = เลข 2
    }


    // เลขอื่น: ให้นักเรียนเขียน else if (n == 0) ... else if (n == 9)
   else  if (n == 0) {                             // ถ้าไม่ใช่ 2 ให้เช็คต่อว่าเป็น 0 ไหม (else if = เช็คเงื่อนไขถัดไป)
      digitalWrite(pinA, HIGH);   // a ติด
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, HIGH);       // e ติด
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, LOW);        // g ดับ -> a,b,c,d,e,f ติด = เลข 0 (วงรอบ ไม่มีขีดกลาง)


    }
     else  if (n == 1) {                             // เช็คว่าเป็น 1 ไหม
      digitalWrite(pinA, LOW);    // a ดับ
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, LOW);        // d ดับ
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, LOW);        // f ดับ
  digitalWrite(pinG, LOW);        // g ดับ -> เหลือ b,c ติด = เลข 1 (ขีดขวา 2 ขีด)
    }
     else  if (n == 3) {                             // เช็คว่าเป็น 3 ไหม
      digitalWrite(pinA, HIGH);   // a ติด
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, LOW);        // f ดับ
  digitalWrite(pinG, HIGH);       // g ติด -> a,b,c,d,g ติด = เลข 3
    }
     else  if (n == 4) {                             // เช็คว่าเป็น 4 ไหม
       digitalWrite(pinA, LOW);   // a ดับ
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, LOW);        // d ดับ
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, HIGH);       // g ติด -> b,c,f,g ติด = เลข 4
    }
     else  if (n == 5) {                             // เช็คว่าเป็น 5 ไหม
     digitalWrite(pinA, HIGH);    // a ติด
  digitalWrite(pinB, LOW);        // b ดับ
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, HIGH);       // g ติด -> a,c,d,f,g ติด = เลข 5
    }
     else  if (n == 6) {                             // เช็คว่าเป็น 6 ไหม
      digitalWrite(pinA, HIGH);   // a ติด
  digitalWrite(pinB, LOW);        // b ดับ
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, HIGH);       // e ติด
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, HIGH);       // g ติด -> a,c,d,e,f,g ติด = เลข 6
    }
     else  if (n == 7) {                             // เช็คว่าเป็น 7 ไหม
       digitalWrite(pinA, HIGH);  // a ติด
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, LOW);        // d ดับ
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, LOW);        // f ดับ
  digitalWrite(pinG, LOW);        // g ดับ -> a,b,c ติด = เลข 7
    }
     else  if (n == 8) {                             // เช็คว่าเป็น 8 ไหม
  digitalWrite(pinA, HIGH);       // a ติด
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, HIGH);       // e ติด
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, HIGH);       // g ติด -> ติดครบทั้ง 7 ขีด = เลข 8
    }
     else  if (n == 9) {                             // เช็คว่าเป็น 9 ไหม
      digitalWrite(pinA, HIGH);   // a ติด
  digitalWrite(pinB, HIGH);       // b ติด
  digitalWrite(pinC, HIGH);       // c ติด
  digitalWrite(pinD, HIGH);       // d ติด
  digitalWrite(pinE, LOW);        // e ดับ
  digitalWrite(pinF, HIGH);       // f ติด
  digitalWrite(pinG, HIGH);       // g ติด -> a,b,c,d,f,g ติด = เลข 9
    }
  }                               // ปิดเงื่อนไข if (Serial.available() > 0)
}                                 // ปิดฟังก์ชัน loop
