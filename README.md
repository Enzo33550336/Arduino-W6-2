const int pinA = 16;
const int pinB = 17;
const int pinC = 18;
const int pinD = 19;
const int pinE = 21;
const int pinF = 22;
const int pinG = 23;
const int pinDP = 25;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(50);     // ลดเวลารอ parseInt จาก 1000 ms เหลือ 50 ms
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  Serial.println("Type a digit 0-9 and press Enter");
}


void loop() {
  if (Serial.available() > 0) {
    int n = Serial.parseInt();                // อ่านเลขทั้งก้อน เช่น พิมพ์ 2 ได้ 2
    while (Serial.available() > 0) Serial.read();   // ทิ้งตัวขึ้นบรรทัดใหม่ที่ค้างอยู่


    Serial.print("Received: ");
    Serial.println(n);


    if (n == 2) {                             // ตัวอย่างแสดงเฉพาะเลข 2
    digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
    }


    // เลขอื่น: ให้นักเรียนเขียน else if (n == 0) ... else if (n == 9)
   else  if (n == 0) {                             // ตัวอย่างแสดงเฉพาะเลข 2
      digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);


    }
     else  if (n == 1) {                             // ตัวอย่างแสดงเฉพาะเลข 2
      digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
    }
     else  if (n == 3) {                             // ตัวอย่างแสดงเฉพาะเลข 2
      digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
    }
     else  if (n == 4) {                             // ตัวอย่างแสดงเฉพาะเลข 2
       digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
    }
     else  if (n == 5) {                             // ตัวอย่างแสดงเฉพาะเลข 2
     digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
    }
     else  if (n == 6) {                             // ตัวอย่างแสดงเฉพาะเลข 2
      digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
    }
     else  if (n == 7) {                             // ตัวอย่างแสดงเฉพาะเลข 2
       digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
    }
     else  if (n == 8) {                             // ตัวอย่างแสดงเฉพาะเลข 2
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
    }
     else  if (n == 9) {                             // ตัวอย่างแสดงเฉพาะเลข 2
      digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
    }
  }
}
