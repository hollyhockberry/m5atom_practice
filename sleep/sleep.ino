#include "M5Atom.h"

namespace {

void enter_sleep() {
  pinMode(GPIO_NUM_39, INPUT_PULLUP);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, LOW);
  esp_deep_sleep_start();
}

} // namespace

void setup() {
  M5.begin(true, /* SerialEnable */
           true, /* I2CEnable */
           true  /* DisplayEnable */);
  M5.dis.setBrightness(20);
  M5.dis.clear();	

  const esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();

  switch (cause) {
  case ESP_SLEEP_WAKEUP_EXT0:
  case ESP_SLEEP_WAKEUP_EXT1:
  case ESP_SLEEP_WAKEUP_TIMER:
  case ESP_SLEEP_WAKEUP_TOUCHPAD:
  case ESP_SLEEP_WAKEUP_ULP:
  case ESP_SLEEP_WAKEUP_GPIO:
  case ESP_SLEEP_WAKEUP_UART:
    break;
  default:
    enter_sleep();
    break;
  }
}

void loop() {
  const int kDelay = 5000, kInterval = 100;
  for (int i = 0; i < kDelay; i += kInterval) {
    M5.dis.drawpix(0, random(0, 0xffffff));
    delay(kInterval);
  }

  M5.dis.clear();	
  delay(100);
  enter_sleep();
}
