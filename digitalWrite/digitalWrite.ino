int pinSvetodiod = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinSvetodiod, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinSvetodiod, HIGH);
  delay(1000);
  digitalWrite(pinSvetodiod, LOW);
  delay(1000);
}
