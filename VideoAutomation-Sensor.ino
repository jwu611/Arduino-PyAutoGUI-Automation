  int trig = 4;
  int ECHO_PIN = 5;
  #define maxDist 200 // in cm
  #define pauseDist 60
  #define volDist 40
  long initialDist; 
  long dist;
  long time_taken;
  long oldDist;
  
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  calcDist(trig, ECHO_PIN);
  initialDist = dist;

}

void loop() {
  calcDist(trig, ECHO_PIN);
  if(dist < initialDist){  //dist >= pauseDist && dist < pauseDist+10
     delay(500);
     calcDist(trig, ECHO_PIN);
     if(dist < initialDist){
      Serial.println("Play/Pause");
     }
  }
  delay(200);
  
}

void calcDist(int trigger, int ECHO_PIN)
{ 
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  time_taken = pulseIn(ECHO_PIN, HIGH);
  dist= time_taken*0.034/2;
  if (dist>maxDist)
  dist = maxDist;
  
  if(dist <= volDist && dist > volDist-20){
    oldDist = dist;
    calcDist(trig, ECHO_PIN);

    if(dist < oldDist){ //getting closer = volUp
      Serial.println("VolUp");
    }
    else if (dist > oldDist){
      Serial.println("VolDown");
    }
  }
}

  
