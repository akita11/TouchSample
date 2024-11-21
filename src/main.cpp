#include <M5Unified.h>

int last_value = 0;
int cur_value = 0;

void setup() {
  M5.begin();
  pinMode(26, INPUT); // PortB-2, Touch2
  M5.Display.setTextColor(YELLOW);
  M5.Display.setTextSize(2);
  M5.Display.setCursor(80, 0);
  M5.Display.println("Button example");
  M5.Display.setTextColor(WHITE);
}

void loop() {
  cur_value = digitalRead(26);
  M5.Lcd.setCursor(0, 45);
  M5.Lcd.print("Value: ");
  M5.Lcd.setCursor(0, 85);
  M5.Lcd.print("State: ");
  if (cur_value != last_value) {
    M5.Lcd.fillRect(85, 45, 75, 85, BLACK);
    if (cur_value == 0) {
	    M5.Lcd.setCursor(95, 45);
	    M5.Lcd.print("0");  // display the status
	    M5.Lcd.setCursor(95, 85);
	    M5.Lcd.print("pre");
    }
    else {
	    M5.Lcd.setCursor(95, 45);
	    M5.Lcd.print("1");  // display the status
	    M5.Lcd.setCursor(95, 85);
	    M5.Lcd.print("rel");
    }
    last_value = cur_value;
  }
}
