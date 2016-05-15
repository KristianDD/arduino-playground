void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int sluchaino;

  randomSeed(analogRead(A0));
  for(int i = 0; i < 10; i++){
    sluchaino = random(50);

    Serial.println(sluchaino);
    delay(200);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
