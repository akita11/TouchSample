#include <M5Unified.h>
#include "M5UnitENV.h"

int last_value = 0;
int cur_value = 0;

SHT3X sht3x;

void setup() {
  M5.begin();
  pinMode(26, INPUT); // PortB-2, Touch2

	if (!sht3x.begin(&Wire, SHT3X_I2C_ADDR, 32, 33, 400000U)) {
		printf("Couldn't find SHT3X\n");
		while (1) delay(1);
	}

  M5.Display.setTextColor(YELLOW);
  M5.Display.setTextSize(2);
  M5.Display.setCursor(80, 0);
  M5.Display.println("Button example");
  M5.Display.setTextColor(WHITE);
}

void loop() {
	if (sht3x.update()) {
  	M5.Lcd.setCursor(0, 0);
		M5.Lcd.printf("Temp[degC]: %f", sht3x.cTemp);
	}
  cur_value = digitalRead(26);
  M5.Lcd.setCursor(0, 45); M5.Lcd.print("Value: ");
  M5.Lcd.setCursor(0, 85); M5.Lcd.print("State: ");
  if (cur_value != last_value) {
    M5.Lcd.fillRect(85, 45, 75, 85, BLACK);
    if (cur_value == 0) {
	    M5.Lcd.setCursor(95, 45); M5.Lcd.print("0");  // display the status
	    M5.Lcd.setCursor(95, 85); M5.Lcd.print("pre");
    }
    else {
	    M5.Lcd.setCursor(95, 45); M5.Lcd.print("1");  // display the status
	    M5.Lcd.setCursor(95, 85); M5.Lcd.print("rel");
    }
    last_value = cur_value;
  }
}
