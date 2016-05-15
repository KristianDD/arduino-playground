#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int startButton = 0;
int diodes[9] = {};

int currentDiode;
int minDiodePin;
int maxDiodePin;

unsigned long result = 0;
unsigned long previousMillis = 0;
int interval = 1000;
int minInterval = 200;

int currentButton;
bool isGameOver = false;

void displayNumber(int num){
  display.println(String(num));
  display.display();
}

void setDefaultState(){
  currentDiode = NULL;
  currentButton = NULL;
  previousMillis = millis();
  result = 0;
  interval = 1000;
  isGameOver = false;
  
  for (int i = 0; i < (sizeof(diodes)/sizeof(int)); i++) {
    if(diodes[i] != NULL){
        digitalWrite(i, LOW);
      }
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Start in..");
  display.display();
  delay(1000);
  displayNumber(3);
  delay(1000);
  displayNumber(2);
  delay(1000);
  displayNumber(1);
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Playing...");
  display.display();
}

void changeDiode(){
  randomSeed(analogRead(A0));
  int randomDiode = random(minDiodePin, maxDiodePin + 1);
  
  while(randomDiode == currentDiode){
    randomDiode = random(minDiodePin, maxDiodePin + 1);
  }
  
  currentDiode = randomDiode;
  
  for (int i = 0; i < (sizeof(diodes)/sizeof(int)); i++) {
    if(diodes[i] != NULL){
      if(currentDiode != i){
        digitalWrite(i, LOW);
      } else {
        digitalWrite(i, HIGH);
      }
    }
  }
  
  currentButton = NULL;
}

void checkButtons(){
  for (int i = 0; i < (sizeof(diodes)/sizeof(int)); i++) {
    if(diodes[i] != NULL){
      if(digitalRead(diodes[i]) == LOW){
        currentButton = diodes[i];
        break;
      }
    }
  }
}

void gameOver(){
  isGameOver = true;
  Serial.println(result);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Game Over");
  display.setTextSize(1);
  display.println();
  display.println("Your score is: " + String(result));
  display.display();
}

void setup()   { 
  
  diodes[6] = 3;
  diodes[7] = 4;
  diodes[8] = 5;
                 
  Serial.begin(9600);
  
  for (int i = 0; i < (sizeof(diodes)/sizeof(int)); i++) {
    if(diodes[i] != NULL){
      pinMode(i, OUTPUT);
      
      pinMode(diodes[i], INPUT_PULLUP);
      
      if(minDiodePin == NULL){
        minDiodePin = i;
      }
      
      maxDiodePin = i;
    }
  }
  
  pinMode(startButton, INPUT_PULLUP);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  setDefaultState();
/*  testdrawchar();
  display.display();
  delay(2000);
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(2000);
  display.clearDisplay();*/
  
  
}


void loop() {
  if(digitalRead(startButton) == LOW && isGameOver){
    setDefaultState();
  }
  
  if(isGameOver){
    return;
  }
  
  unsigned long currentMillis = millis();
  
  if(currentButton == NULL){
    checkButtons();
  }
  
  if(((currentMillis - previousMillis) > interval) || ((currentMillis - previousMillis) < 0)){
    previousMillis = currentMillis;
    
    if(interval > minInterval){
      interval = interval - 10;
    }
    
    if(diodes[currentDiode] != currentButton){
      gameOver();
      changeDiode();
    } else {
      if(currentDiode != NULL){
        result = result + 1;
      }
      changeDiode();
    }
  }
}
