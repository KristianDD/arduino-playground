int buttonPin = 10;
int ledPin = 13;
int pokazanie;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pokazanie = digitalRead(buttonPin);

  if(pokazanie == HIGH){
    digitalWrite(ledPin, HIGH);
  }

   if(pokazanie == LOW){
    digitalWrite(ledPin, LOW);
  }
}
