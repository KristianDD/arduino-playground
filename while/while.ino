int pinDiod = 13;
int potentiometerPin = A1;
int buttonPin = 7;
int pokazaniePot;
int pokazanieButton;




void setup() {
  // put your setup code here, to run once:
  pinMode(pinDiod, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pokazaniePot = analogRead(potentiometerPin);
  pokazanieButton = digitalRead(buttonPin);

 if(pokazaniePot > 600){
    while(pokazanieButton == HIGH){
      digitalWrite(pinDiod, HIGH);
      delay(100);
      digitalWrite(pinDiod, LOW);
      delay(100);
       pokazanieButton = digitalRead(buttonPin);
    }
 } else {
  digitalWrite(pinDiod, LOW);
 }
}
