#include <IndIOButtonPanel.h>
#include <UC1701.h>

static UC1701 lcd;

int lastButton;
int currentButton;

IndIOButtonPanel btns;

void setup() {
  btns = IndIOButtonPanel();
  lastButton = NONE_PRESSED;
  currentButton = NONE_PRESSED;
  lcd.begin();
  screenWrite(NONE_PRESSED);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = btns.readButtonPanel();  

  if(currentButton != lastButton){
    lcd.setCursor(0,0);
    lcd.print("               ");
    lcd.setCursor(0,0);
    screenWrite(currentButton);
    lastButton = currentButton;
  }
}

void screenWrite(int btn){
  switch(currentButton){
      case ENTER_PRESSED:
        lcd.print("ENTER");
        break;
      case UP_PRESSED:
        lcd.print("UP");
        break;
      case DOWN_PRESSED:
        lcd.print("DOWN");
        break;
      default:
        lcd.print("NOTHING PRESSED");
    }
}


