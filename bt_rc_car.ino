//**Bluetooth Kontrollü araba yapım kodu**//

#include <AFMotor.h> //Kütüphane ekleme
AF_DCMotor motor1(1); //Motorların bağlandığı pinler
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int Speed = 230; //motorların hızını belirlenmesi
char value;
void setup() {
  Serial.begin(38400);    
  motor1.setSpeed(Speed); 
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);


}

void loop() {
  if (Serial.available() > 0) { //Bluetooth bağlantısının kontrolü//
    value = Serial.read();
  }
  //Motorların çalışma yönlerinin belirlenmesi
  if (value == 'F') {  //
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (value == 'B') {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } else if (value == 'L') {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (value == 'R') {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } else {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }

}
