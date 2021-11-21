// GxEPD_MinimumExample by Jean-Marc Zingg
#define LILYGO_T5_V213
#include <boards.h>
#include <GxEPD.h>



// select the display class to use, only one, copy from GxEPD_Example
//#include <GxDEPG0213BN/GxDEPG0213BN.h>
//#include <GxGDEH0213B72/GxGDEH0213B72.h>  // 2.13" b/w  old panel , form GoodDisplay
#include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w  old panel , form GoodDisplay
//#include <GxGDEM0213B74/GxGDEM0213B74.h>  // 2.13" b/w  form GoodDisplay 4-color
//#include <GxGDEW0213M21/GxGDEW0213M21.h>  // 2.13"  b/w Ultra wide temperature , form GoodDisplay
//#include <GxDEPG0213BN/GxDEPG0213BN.h>    // 2.13" b/w  form DKE GROUP

// the physical number of pixels (for controller parameter)
//#define GxGDEH0213B73_X_PIXELS 128
//#define GxGDEH0213B73_Y_PIXELS 250
// note: the visible number of display pixels is 122*250, see GDEH0213B72 V1.1 Specification.pdf
//#define GxGDEH0213B73_VISIBLE_WIDTH 122

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// constructor for AVR Arduino, copy from GxEPD_Example else
GxIO_Class io(SPI,  EPD_CS, EPD_DC,  EPD_RSET);
GxEPD_Class display(io, EPD_RSET, EPD_BUSY);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void cleanDisplay() {
  for (uint16_t r = 0; r < 2; r++) {
    display.fillScreen(GxEPD_WHITE);
    display.updateWindow(0,0,display.width(), display.height());
    delay(500);
  }
}


//-----------------------------------------------------------------------------
//include Bitmaps
#include "bitmap/2021_01_16_027_1.h"
#include "bitmap/2021_01_19_011_1.h"
#include "bitmap/2021_02_06_031.h"
#include "bitmap/2021_01_18_004.h"
#include "bitmap/2021_03_16_037.h"
#include "bitmap/2021_03_08_035.h"
#include "bitmap/2021_02_14_030.h"
#include "bitmap/2021_01_18_041.h"
#include "bitmap/2021_02_14_012.h"

void drawBitMap() {
  display.setRotation(0);
  //display.drawExampleBitmap(BM2020_08_31_008, 0, 0, 128, 250, GxEPD_BLACK);
  //display.updateWindow(0,0,display.width(), display.height());
  //delay(5000);
  display.drawExampleBitmap(BM2021_01_16_027_1, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_01_19_011_1, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_02_06_031, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_01_18_004, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_03_16_037, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_03_08_035, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_02_14_030, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_01_18_041, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
  display.drawExampleBitmap(BM2021_02_14_012, 0, 0, 128, 250, GxEPD_BLACK);
  display.updateWindow(0,0,display.width(), display.height());
  delay(5000);
}



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);

  display.init();
  display.eraseDisplay();

  Serial.print("width: ");
  Serial.println(display.width());
  Serial.print("height: ");
  Serial.println(display.height());
  
  cleanDisplay();
}



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void loop() 
{
      drawBitMap();
}
//-----------------------------------------------------------------------------
