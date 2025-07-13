#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS 5
#define TFT_RST 9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 6

// example: https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/examples/graphicstest/graphicstest.ino

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  tft.init(240, 240); // Init ST7789 240x240

  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  // tft.setSPISpeed(40000000);

  Serial.println(F("Initialized"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  // large block of text
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(5);
  tft.println(F("I love you Sabrina."));
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}