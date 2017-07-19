/*
  e-Gizmo RPI-1031 4-Direction Sensor
  
  This is a sample sketch for Tilt direction sensor
  to display the sensor output positions.
  
  For the RPI-1031 - http://www.sparkfun.com/products/10621

  Modified by e-Gizmo Mechatronix Central
  http://www.e-gizmo.com
  July 18,2017

*/

#define TILT_S1 4
#define TILT_S2 5
#define LED_TOP 8
#define LED_RIGHT 9
#define LED_BOTTOM 10
#define LED_LEFT 11

void setup(){
  Serial.begin(9600);
  pinMode(TILT_S1, INPUT);
  pinMode(TILT_S2, INPUT);
  pinMode(LED_TOP, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_BOTTOM, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
}

void loop(){
  int position = GET_TILT_POSITION();
  Serial.println(position);
  //TOP
  if(position == 0)
  {
    digitalWrite(LED_TOP, HIGH); 
    digitalWrite(LED_RIGHT, LOW);
    digitalWrite(LED_BOTTOM, LOW);
    digitalWrite(LED_LEFT, LOW);
  }
  //RIGHT
  if(position == 2)
  {
    digitalWrite(LED_TOP, LOW); 
    digitalWrite(LED_RIGHT, HIGH);
    digitalWrite(LED_BOTTOM, LOW);
    digitalWrite(LED_LEFT, LOW);
  }
  //LEFT
   if(position == 1)
  {
    digitalWrite(LED_TOP, LOW); 
    digitalWrite(LED_RIGHT, LOW);
    digitalWrite(LED_BOTTOM, LOW);
    digitalWrite(LED_LEFT, HIGH);
  }
  //BOTTOM
   if(position == 3)
  {
    digitalWrite(LED_TOP, LOW); 
    digitalWrite(LED_RIGHT, LOW);
    digitalWrite(LED_BOTTOM, HIGH);
    digitalWrite(LED_LEFT, LOW);
  }  
  delay(200); //DELAY
}

int GET_TILT_POSITION(){
  int S1 = digitalRead(TILT_S1);
  int S2 = digitalRead(TILT_S2);
  return (S1 << 1) | S2; //BITWISE MATH
}




