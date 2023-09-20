#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  10 
#define ECHO_PIN     11 
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

float duration, distance;

Servo myservo;  // create servo object to control a servo

// twelve servo objects can be created on most boards


int pos = 0;    // variable to store the servo position
   
int it = 10;

void setup() {

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //pinMode(trigPin, OUTPUT);
  //pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {

/*  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(15);                       // waits 15ms for the servo to reach the position

  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(15);                       // waits 15ms for the servo to reach the position

  }

   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
*/

  int i = 0;
  int t = 0;
  int a = 0;

  for (i = 0; i < 180; i ++)
  {
    unsigned int uS = sonar.ping();
    myservo.write(i);
    delay(20);
    for (t = 0; t < it; t++)
    {
      uS = sonar.ping();
      a = uS/US_ROUNDTRIP_CM + a;
      delay(30);
    }
    
    a = a / (it-1);
    t = 0;

    Serial.println(a); 
    a = 0;
  }


}
