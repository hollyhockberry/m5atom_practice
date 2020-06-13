#include <M5StickC.h>
#include <BleKeyboard.h>

//https://github.com/T-vK/ESP32-BLE-Keyboard

static BleKeyboard bleKeyboard("Atom BLE button");

void setup() {
    M5.begin();
    bleKeyboard.begin();
}

void loop() {
    M5.update();
    if (bleKeyboard.isConnected()) {
        if (M5.BtnB.wasPressed()) {
            bleKeyboard.write(KEY_LEFT_ARROW);
        }
    }
}
