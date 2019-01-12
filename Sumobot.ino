void stp();
boolean detectWhite();
boolean detectIR();


int motorRForward = 2;
int motorRBackward=3;
int motorLForward=4;
int motorLBackward=5;
int IROutputPin=6;
const int IRInput=A1;
const int whiteLine=A0;

 
void setup() 
{ 
  pinMode(motorRForward, OUTPUT);
  pinMode(motorRBackward, OUTPUT);
  pinMode(motorLForward, OUTPUT);
  pinMode(motorLBackward, OUTPUT);
  pinMode(whiteLine, INPUT);
  pinMode(IROutputPin,OUTPUT);
  pinMode(IRInput,INPUT);
  digitalWrite(IROutputPin,HIGH);
  Serial.begin(9600);
  delay(5000);
} 
 
 
void loop() {
//  int val = analogRead(IRInput);
//  Serial.println(val);
//  delay(500);
  
//  int proximityADC = analogRead(QRD1114_PIN);
//  float proximityV = (float)proximityADC * 5.0 / 1023.0;
//  Serial.println(proximityV);
//  delay(500);
//  digitalWrite(motorLBackward, HIGH);
//  digitalWrite(motor2Backward, HIGH);

//  if(proximityV>=4.5){
//    
//  
//    delay(1000);
//    digitalWrite(motor1Forward, HIGH);
//    delay(1000);
//    digitalWrite(motor1Forward, LOW);
//    delay(1000);  
//    digitalWrite(motor1Backward, HIGH);
//    delay(1000); 
//    digitalWrite(motor1Backward, LOW);
//    delay(1000);
//    digitalWrite(motor2Forward, HIGH);
//    delay(1000);
//    digitalWrite(motor2Forward, LOW);
//    delay(1000);
//    digitalWrite(motor2Backward, HIGH);
//    delay(1000);
//    digitalWrite(motor2Backward, LOW);
  moveForward();
  
  
} 

float degreesToSec(float deg, float sec) {
  return((sec / 360.0)*deg);
}

void rotate(int deg){
  digitalWrite(motorLBackward, HIGH);
  digitalWrite(motorRForward, HIGH);
  delay(degreesToSec(deg, 5450));
  stp();
  
}

void rotateTest(){
  digitalWrite(motorLBackward, HIGH);
  digitalWrite(motorRForward, HIGH);
}

void moveBackward(){
  digitalWrite(motorLBackward, HIGH);
  digitalWrite(motorRBackward, HIGH);
  delay(900);
  stp();
}

void moveForward(){
  digitalWrite(motorLForward, HIGH);
  digitalWrite(motorRForward, HIGH);
  
  if(detectWhite()){
    stp();
    moveBackward();
    rotate(60); 
  }

  if(detectIR()){
    stp();
    rotate(60);
  }
}

boolean detectWhite(){
  int proximityADC = analogRead(whiteLine);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  if(proximityV<4.5){
    return true;
  }
  return false;
}

boolean detectIR(){
  float sum=0;
  int counter=0;
  while(counter<100){
    sum+=analogRead(IRInput);
    counter++;
  }
  sum/=counter;
  if(sum<1019){
    return true;
  }
  return false;
}

void stp(){
  digitalWrite(motorLForward, LOW);
  digitalWrite(motorRForward, LOW);
  digitalWrite(motorLBackward, LOW);
  digitalWrite(motorRBackward, LOW);
  
}


