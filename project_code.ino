#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ecgPin = A0;
float prevValue = 0;

int xPos = 0;
int prevY = 32;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED FAIL");
    while(1);
  }

  Serial.println("OLED OK");
  display.clearDisplay();
}

void loop() {

  int rawValue = analogRead(ecgPin);
  Serial.println(rawValue);

  float filteredValue = (0.7 * prevValue) + (0.3 * rawValue);
  prevValue = filteredValue;

  // Leave top 10 pixels for text
  int yPos = map(filteredValue, 0, 1023, SCREEN_HEIGHT-1, 10);

  // Draw waveform
  display.drawLine(xPos - 1, prevY, xPos, yPos, WHITE);

  prevY = yPos;

  // 🔴 Clear only top area (for text)
  display.fillRect(0, 0, 128, 10, BLACK);

  // 🔴 Show value
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("ECG:");
  display.print(rawValue);

  xPos++;

  if (xPos >= SCREEN_WIDTH) {
    xPos = 0;
    display.clearDisplay();
  }

  display.display();

  delay(500);
} 