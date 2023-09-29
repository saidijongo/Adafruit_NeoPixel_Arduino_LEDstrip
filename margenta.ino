#include <Adafruit_NeoPixel.h>

int dataPin = 6; 

#define numberOfPixels  6 

#define maximumBrightness 255  


Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(numberOfPixels, dataPin); 
                                               

void setup() 
  {
      ledStrip.begin();  
  }


void loop() 
  {
   customLight(); 
   
    
  }


void customLight()  
  {
    setLightsToColour(255,200,0);

  }                                                  




void setLightsToColour(int red, int green, int blue)
     for (uint8_t i = 0; i < numberOfPixels; i++) 
     {
        ledStrip.setPixelColor(i, ledStrip.Color(red, green, blue));
       
     }
     
     ledStrip.show();
  }
