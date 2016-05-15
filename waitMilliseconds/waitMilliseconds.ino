int ledPin = 13;
int ledState = LOW;
unsigned long previousMilliseconds = 0;
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMilliseconds = millis();

  if(currentMilliseconds - previousMilliseconds > interval){
    previousMilliseconds = currentMilliseconds;

    ledState = !ledState;
  }

  digitalWrite(ledPin, ledState);
}
