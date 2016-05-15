int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledPin, 255);
  delay(500);
  analogWrite(ledPin, 128);
  delay(500);
  analogWrite(ledPin, 255/4);
  delay(500);
  analogWrite(ledPin, 0);
  delay(500);
}
