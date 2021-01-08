int buzzer = 10;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 10;

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {

    digitalWrite(buzzer, HIGH);
  }
  else
  {

    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
