#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include "IndIOButtonPanel.h"

int buttonsAnalogValue = 0;

const int buttonsPin = 13;

int buttonEnterState = LOW;
int buttonUpState = LOW;
int buttonDownState = LOW;

IndIOButtonPanel::IndIOButtonPanel(){
	_pin = 13;
}

IndIOButtonPanel::IndIOButtonPanel(int pin){
	_pin = pin;
}
int IndIOButtonPanel::readButtonPanel(){
    
  buttonsAnalogValue = analogRead(buttonsPin);
  
if (buttonsAnalogValue>400 && buttonsAnalogValue< 700 ){
    buttonEnterState = HIGH;
    return ENTER_PRESSED;
  }else{
    buttonEnterState = LOW;
  }
  
  if (buttonsAnalogValue>100 && buttonsAnalogValue<400){
    buttonUpState = HIGH;
    return UP_PRESSED;
  }else{
    buttonUpState = LOW;
  }   
   
  if (buttonsAnalogValue>700 && buttonsAnalogValue<1000 ){
    return DOWN_PRESSED;
    buttonDownState = HIGH;
  }else{
    buttonDownState = LOW;
  }
  
  //No debouncing...
  return NONE_PRESSED;
}