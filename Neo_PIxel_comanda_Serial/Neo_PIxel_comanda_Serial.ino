#include <Adafruit_NeoPixel.h>

#define Pin 9
#define NumarPixeli 8

Adafruit_NeoPixel pixels(NumarPixeli, Pin, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pixels.begin();
}

int rosu = 0;
int verde = 0;
int albastru = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    pixels.clear();
    String DataIn = Serial.readString(); // Citesc valorile RGB (format rrrgggbbb)
    Serial.print("Rosu: ");
    rosu = DataIn.substring(0, 3).toInt(); // Sparg valorile pentru rosu
    Serial.println(rosu);
    Serial.print("Verde: ");
    verde = DataIn.substring(3, 6).toInt(); // Sparg valorile pentru verde
    Serial.println(verde);
    Serial.print("Albastru: ");
    albastru = DataIn.substring(6, 9).toInt(); // Sparg valorile pentru albastru
    Serial.println(albastru);

    for (int foo = 0; foo <= NumarPixeli; ++foo) {
      pixels.setPixelColor(foo, pixels.Color(rosu, verde, albastru));
    }

    pixels.show();
  }
}
