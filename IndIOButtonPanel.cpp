/*
 * IndIOButtonPanel - Simple interface for getting the current pressed button 
 * on Industruino.
 *
 * Copyright (c) 2014 Summit Management Systems, Inc
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include "IndIOButtonPanel.h"

int buttonsAnalogValue = 0;

int buttonEnterState = LOW;
int buttonUpState = LOW;
int buttonDownState = LOW;

IndIOButtonPanel::IndIOButtonPanel(){
	_pin = A5;
}

IndIOButtonPanel::IndIOButtonPanel(int pin){
	_pin = pin;
}
int IndIOButtonPanel::readButtonPanel(){
    
  buttonsAnalogValue = analogRead(_pin);
  
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