#include "M5Atom.h"

void setup()
{
  M5.begin(true, /* SerialEnable */
           true, /* I2CEnable */
           true  /* DisplayEnable */);

  M5.dis.setBrightness(20);
  M5.dis.clear();
}

void loop()
{
  M5.update();
  if (M5.Btn.wasPressed()) {
    M5.dis.drawpix(0, random(0, 0xffffff));
  }
}
