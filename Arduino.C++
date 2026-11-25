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
  Serial.println("Type a digit 0-9 and press Enter");   // พิมพ์ข้อความแนะนำ (println = พิมพ์แล้วขึ้นบรรทัดใหม่) ข้อความนี้ยังเป็นของเวอร์ชันเลข แต่โค้ดนี้รับตัวอักษร
}






void loop() {                  // ฟังก์ชัน loop ทำงาน "วนซ้ำตลอดเวลา" หลัง setup จบ
  if (Serial.available() > 0) {   // เช็คว่ามีข้อมูลเข้ามาใน Serial buffer ไหม (จำนวน byte ที่ค้างอยู่ > 0)
    char c = Serial.read();   // อ่านทีละ 1 ตัวอักษร
    c = toupper(c);           // แปลง a-z เป็น A-Z


    if (c == 'A') {           // ถ้าตัวอักษรที่รับมาคือ A (ใช้ '...' เพราะเป็น char ตัวเดียว)
      // A = a b c e f g
      digitalWrite(pinA, HIGH);   // HIGH = จ่ายไฟ = เซกเมนต์ a ติด
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, LOW);    // LOW = ไม่จ่ายไฟ = เซกเมนต์ d ดับ
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> a,b,c,e,f,g ติด = ตัว A
    } else if (c == 'B') {    // ถ้าไม่ใช่ A ให้เช็คต่อว่าเป็น B ไหม (else if = เช็คเงื่อนไขถัดไป)
      // แสดงเป็น b = c d e f g
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> c,d,e,f,g ติด = ตัว b ตัวเล็ก (ใช้ตัวใหญ่ B ไม่ได้ เพราะจะซ้ำกับเลข 8)
    } else if (c == 'C') {    // เช็คว่าเป็น C ไหม
      // C = a d e f
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, LOW);    // c ดับ
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, LOW);    // g ดับ -> a,d,e,f ติด = ตัว C
    } else if (c == 'D') {    // เช็คว่าเป็น D ไหม
      // แสดงเป็น d = b c d e g
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, LOW);    // f ดับ
      digitalWrite(pinG, HIGH);   // g ติด -> b,c,d,e,g ติด = ตัว d ตัวเล็ก (ใช้ตัวใหญ่ D ไม่ได้ เพราะจะซ้ำกับเลข 0)
    } else if (c == 'E') {    // เช็คว่าเป็น E ไหม
      // E = a d e f g
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, LOW);    // c ดับ
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> a,d,e,f,g ติด = ตัว E
    } else if (c == 'F') {    // เช็คว่าเป็น F ไหม
      // F = a e f g
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, LOW);    // c ดับ
      digitalWrite(pinD, LOW);    // d ดับ
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> a,e,f,g ติด = ตัว F
    }else if (c == 'G') {     // เช็คว่าเป็น G ไหม
      // F = a e f g          // (คอมเม้นเดิมของไฟล์ ก๊อปมาจาก F ไม่ตรงกับ G จริงๆ G คือ a c d e f g)
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> a,c,d,e,f,g ติด = ตัว G (หน้าตาเหมือนเลข 6)
    }else if (c == 'H') {     // เช็คว่าเป็น H ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง H จริงๆ H คือ b c e f g)
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, LOW);    // d ดับ
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> b,c,e,f,g ติด = ตัว H
    }else if (c == 'I') {     // เช็คว่าเป็น I ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง I จริงๆ I คือ b c)
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, LOW);    // d ดับ
      digitalWrite(pinE, LOW);    // e ดับ
      digitalWrite(pinF, LOW);    // f ดับ
      digitalWrite(pinG, LOW);    // g ดับ -> b,c ติด = ตัว I (เหมือนเลข 1)
    }else if (c == 'J') {     // เช็คว่าเป็น J ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง J จริงๆ J คือ b c d)
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, LOW);    // e ดับ
      digitalWrite(pinF, LOW);    // f ดับ
      digitalWrite(pinG, LOW);    // g ดับ -> b,c,d ติด = ตัว J
    }else if (c == 'L') {     // เช็คว่าเป็น L ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง L จริงๆ L คือ d e f)
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, LOW);    // c ดับ
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, LOW);    // g ดับ -> d,e,f ติด = ตัว L
    }else if (c == 'O') {     // เช็คว่าเป็น O ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง O จริงๆ O คือ a b c d e f)
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, LOW);    // g ดับ -> a,b,c,d,e,f ติด = ตัว O (เหมือนเลข 0)
    }else if (c == 'P') {     // เช็คว่าเป็น P ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง P จริงๆ P คือ a b e f g)
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, LOW);    // c ดับ
      digitalWrite(pinD, LOW);    // d ดับ
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, HIGH);   // g ติด -> a,b,e,f,g ติด = ตัว P
    }else if (c == 'S') {     // เช็คว่าเป็น S ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง S จริงๆ S คือ a c d g)
      digitalWrite(pinA, HIGH);   // a ติด
      digitalWrite(pinB, LOW);    // b ดับ
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, LOW);    // e ดับ
      digitalWrite(pinF, LOW);    // f ดับ
      digitalWrite(pinG, HIGH);   // g ติด -> a,c,d,g ติด = ตัว S (ในโค้ดนี้ไม่มีขีด f ต่างจากเลข 5)
    }else if (c == 'U') {     // เช็คว่าเป็น U ไหม
      // F = a e f g          // (คอมเม้นเดิมก๊อปมา ไม่ตรง U จริงๆ U คือ b c d e f)
      digitalWrite(pinA, LOW);    // a ดับ
      digitalWrite(pinB, HIGH);   // b ติด
      digitalWrite(pinC, HIGH);   // c ติด
      digitalWrite(pinD, HIGH);   // d ติด
      digitalWrite(pinE, HIGH);   // e ติด
      digitalWrite(pinF, HIGH);   // f ติด
      digitalWrite(pinG, LOW);    // g ดับ -> b,c,d,e,f ติด = ตัว U
    }
    // G-Z ให้นักเรียนเขียนเอง (ตัวขึ้นบรรทัดใหม่ไม่ตรงกับเงื่อนไขใด จึงถูกข้ามไปเอง)
  }                               // ปิดเงื่อนไข if (Serial.available() > 0)
}                                 // ปิดฟังก์ชัน loop