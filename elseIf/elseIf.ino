int pins[] = {9,10,11,12,13};

int potenciometerPin = A1;
int pokazanie;

void lightPinsFromTo(int startTo){
  for(int i=0; i < 5; i++){
    if(i < startTo){
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  };
}

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i < 5; i++){
    pinMode(pins[i], OUTPUT);
  };
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pokazanie = analogRead(potenciometerPin);

  Serial.println(pokazanie);
  if(pokazanie < 200){
     lightPinsFromTo(0);
  } else if(pokazanie < 400){
    lightPinsFromTo(1);
  }  else if(pokazanie < 600){
    lightPinsFromTo(2);
  }  else if(pokazanie < 800){
    lightPinsFromTo(3);
  }  else if(pokazanie < 900){
    lightPinsFromTo(4);
  } else {
    lightPinsFromTo(5);
  }
}
