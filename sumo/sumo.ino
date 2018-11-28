#include <SparkFun_TB6612.h>

#define UP_KEY 273
#define DOWN_KEY 274
#define LEFT_KEY 276
#define RIGHT_KEY 275
#define BUZZER_PIN 10

#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 3
#define PWMB 9
#define STBY 5

const int offsetA = 1;
const int offsetB = 1;

Motor leftMotor = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor rightMotor = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

bool _forward, _backward, _left, _right;
int speed = 255;

void setup() {
  Serial.begin(9600);
}

void updateMotors(){
  if(_forward){
    if(_left){  // forward-left
      leftMotor.drive(speed/2);
      rightMotor.drive(speed);
    }else if(_right){ // forward-right
      leftMotor.drive(speed);
      rightMotor.drive(speed/2);
    }else{  // just forward
      leftMotor.drive(speed);
      rightMotor.drive(speed);
    }
  }else if(_backward){
    if(_left){  // backward-left
      leftMotor.drive(-aspeed/2);
      rightMotor.drive(-speed);
    }else if(_right){ // backward-right
      leftMotor.drive(-speed);
      rightMotor.drive(-speed/2);
    }else{  // just backward
      leftMotor.drive(-speed);
      rightMotor.drive(-speed);
    }
  }else{
    if(_left){  // just left
      rightMotor.drive(speed);
      leftMotor.drive(-speed);
    }else if(_right){ // just right
      leftMotor.drive(speed);
      rightMotor.drive(-speed);
    }else{
      leftMotor.brake();
      rightMotor.brake();
    }
  }
}

// action will be either 'd' or 'u' for key down or key up
void handleInput(int key, char action){
  if(key == UP_KEY){
    if(action == 'd' && !_forward){
      _forward = true;
      _backward = false;
    }else if(action == 'u' && _forward){
      _forward = false;
    }
  }else if(key == DOWN_KEY){
    if(action == 'd' && !_backward){
      _backward = true;
      _forward = false;
    }else if(action == 'u' && _backward){
      _backward = false;
    }
  }else if(key == LEFT_KEY){
    if(action == 'd' && !_left){
      _left = true;
      _right = false;
    }else if(action == 'u' && _left){
      _left = false;
    }
  }else if(key == RIGHT_KEY){
    if(action == 'd' && !_right){
      _right = true;
      _left = false;
    }else if(action == 'u' && _right){
      _right = false;
    }
  }else if(action == 'd'){
    input_sound(key);
  }
  updateMotors();
}

void input_sound(int key){
  if(key == 97){
    tone(BUZZER_PIN, NOTE_B4, 100);
  }else if(key == 115){
    tone(BUZZER_PIN, NOTE_C5, 100);
  }else if(key == 100){
    tone(BUZZER_PIN, NOTE_D5, 100);
  }else if(key == 102){
    tone(BUZZER_PIN, NOTE_E5, 100);
  }else if(key == 103){
    tone(BUZZER_PIN, NOTE_F5, 100);
  }else if(key == 104){
    tone(BUZZER_PIN, NOTE_G5, 100);
  }else if(key == 106){
    tone(BUZZER_PIN, NOTE_A5, 100);
  }else if(key == 107){
    tone(BUZZER_PIN, NOTE_B5, 100);
  }else if(key == 108){
    tone(BUZZER_PIN, NOTE_C6, 100);
  }else if(key == 101){
    tone(BUZZER_PIN, NOTE_CS5, 100);
  }else if(key == 114){
    tone(BUZZER_PIN, NOTE_DS5, 100);
  }else if(key == 121){
    tone(BUZZER_PIN, NOTE_FS5, 100);
  }else if(key == 117){
    tone(BUZZER_PIN, NOTE_GS5, 100);
  }else if(key == 105){
    tone(BUZZER_PIN, NOTE_AS5, 100);
  }else if(key == 112){
    tone(BUZZER_PIN, NOTE_CS6, 100);
  }
}

void loop() {
  if(Serial.available()){
    String data = Serial.readStringUntil('\n');
    int separator = data.indexOf(',');
    int key = data.substring(0, separator).toInt();
    char action = data.charAt(separator+1);
    handleInput(key, action);
  }
}
