char var;

int m11 = 10; //left forward
int m12 = 11; //left backwaed
int m21 = 12; //right forward
int m22 = 13; //right backward

int trig = 9;
int echo = 8;
void setup() {

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(trig,HIGH);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  Serial.println(distance);
  Serial.println("CM");
  
  if (Serial.available() > 0)
  {
    String var = Serial.readString();

    Serial.println(var);


    if (var == "Forward")
    {
      digitalWrite(10, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);

      Serial.println("Forward");
    }
    if (var == "Backward")
    {
      digitalWrite(11, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(12, LOW);

      Serial.println("Back");
    }
    if (var == "Right")
    {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(10, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);


      Serial.println("Right");
    }
    if (var == "Left")
    {
      digitalWrite(12, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(10, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);


      Serial.println("Left");
    }
    if (var == "Stop")
    {
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      Serial.println("Stop");
      }
    if ((distance<=20)) 
    {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(10, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);

      }
  }
}
