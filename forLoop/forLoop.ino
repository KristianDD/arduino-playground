int ledPin = 11;
int ledPin2 = 10;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int qrkost = 0; qrkost < 255; qrkost++){
    analogWrite(ledPin, qrkost);
    analogWrite(ledPin2, 255 - qrkost);
    delay(10);
  }
  for(int qrkost = 255; qrkost > 0; qrkost--){
    analogWrite(ledPin, qrkost);
    analogWrite(ledPin2, 255 - qrkost);
    delay(10);
  }
}
