int potentiometerPin = A0;
int pokazanie;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pokazanie = analogRead(potentiometerPin);
  Serial.println(pokazanie);
  delay(100);
}
