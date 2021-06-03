//DFPlayer Mini-------------------------------------------
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
SoftwareSerial myDFplayerSerial(10,11); //RX ,TX 
DFRobotDFPlayerMini myDFplayer;

// PCA9685------------------------------------------------
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150
#define SERVOMAX 600
int rightelbow = 0;           //180->0
int rightshoulderside = 1;    //180->0
int rightshoulderver = 2;     //160->0
int leftelbow = 3;            //0->180
int leftshoulderside = 4;     //0->180
int leftshoulderver = 5;      //20->180
int neck = 6;

//servo move
void servo_write(int n, int ang){
  ang = map(ang,0,180,SERVOMIN,SERVOMAX);
  pwm.setPWM(n,0,ang);
}

//---------------------------------------------------------
void setup() {
  //setup Serial
  Serial.begin(9600);
  
  //setup DFPlayer Mini
  myDFplayerSerial.begin(9600);
  myDFplayer.begin( myDFplayerSerial );
  myDFplayer.volume(60);

  //setup PCA9685
  pwm.begin();
  pwm.setPWMFreq(60);
  nomal();

}

//---------------------------------------------------------
void loop(){
  if( Serial.available() > 0 ){
  delay(1000);  

  char branch = Serial.read();
  
  Serial.println(" 1 =>　おはよう ");
  Serial.println(" 2 =>　こんにちは ");
  Serial.println(" 3 =>　ありがとうございました ");
  Serial.println(" 4 => こっちきて");
  Serial.println(" 5 => ばいばい");
  Serial.println(" 6 => ヨーソロ");
  Serial.println("");

  switch (branch) {
    //1 =>　おはよう
    case '1':
    Serial.println(" 1 =>　おはよう ");
    Serial.println("");
    play_01();
    ohayou();
    ohayou();
    break;
    //2 =>　こんにちは
    case '2':
    Serial.println(" 2 =>　こんにちは ");
    Serial.println("");
    play_03();
    konnitiha();
    konnitiha();
    break;
    //3 =>　ありがとうございました
    case '3':
    Serial.println(" 3 =>　ありがとうございました ");
    Serial.println("");
    play_04();
    aisatu();
    break;
    //4 => きて
    case '4':
    Serial.println(" 4 => こっちきて");
    Serial.println("");
    play_05();
    come();
    break;
    //5 => ばいばい
    case '5':
    Serial.println(" 5 => ばいばい");
    Serial.println("");
    play_02();
    konnitiha();
    konnitiha();
    break;

    case '6':
    Serial.println(" 6 => ヨーソロ");
    yosoro();
    break;
    
  }
  delay(500);
  }
  nomal();
  delay(10000);
  play_05();
  come();
  
}
