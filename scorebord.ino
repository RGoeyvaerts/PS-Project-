#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

const int buttonPin1 = 26;
const int buttonPin2 = 25;
const int buttonPin3 = 27;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;


void setup()   
{      
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin1, INPUT_PULLUP);

  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin2, INPUT_PULLUP);

  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin3, INPUT_PULLUP);
	// initialize with the I2C addr 0x3C
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

	// Clear the buffer.
	display.clearDisplay();

	// Display Text
  display.setCursor(0,0);
	display.setTextSize(2);
  display.setTextColor(WHITE);
	display.println("Robot");
  display.println("Football");
	display.display();
	display.startscrollright(0x00, 0x07);
	delay(2000);
	display.stopscroll();
	delay(1000);
	display.startscrollleft(0x00, 0x07);
	delay(2000);
	display.stopscroll();
	delay(1000);    
	display.startscrolldiagright(0x00, 0x07);
	delay(2000);
	display.startscrolldiagleft(0x00, 0x07);
	delay(2000);
	display.stopscroll();
	display.clearDisplay();



	
}

void loop() {
  int scoreOrange = 0;
  int scoreBlue = 0;

  while (true){
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    Serial.println(buttonState1);
    Serial.println(buttonState2);
    Serial.println(buttonState3);
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH
    if (buttonState1 == LOW) {
    // turn LED on
      scoreOrange ++;
      delay(800);
    }
    if (buttonState2 == LOW) {
    // turn LED off
      scoreBlue ++;
      delay(800);
    }
    if (buttonState3 == LOW){
      scoreOrange = 0;
      scoreBlue = 0;
      delay(800);
    }
     display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(32,0);
      display.print("score:");
      display.println();
      display.setCursor(32, 16);
      display.print(scoreOrange);
      display.print(" - ");
      display.print(scoreBlue);
      display.display();
      delay(20);
      display.clearDisplay(); 
  }
  

  
}