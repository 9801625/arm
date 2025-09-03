void servo_write(int ch, int ang){ //動かすサーボチャンネルと角度を指定
  ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); //角度（0～180）をPWMのパルス幅（150～500）に変換
  pwm.setPWM(ch, 0, ang);
}
#include <Wire.h>  // I2C通信を行うためのライブラリ
#include <Adafruit_PWMServoDriver.h>

# define SERVOMIN 150            //最小パルス幅 
# define SERVOMAX 600            //最大パルス幅

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
 pwm.begin();          //初期設定
 pwm.setPWMFreq(50);   //PWM周期を50Hzに設定 
 servo_write(1,20);
}          
void loop(){
}