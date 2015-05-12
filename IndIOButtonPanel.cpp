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
 *
 * Code used from IndustruinoDemoCode_32u4.ino
 */
 
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include "IndIOButtonPanel.h"

//Initial States
int readState = NONE_PRESSED;
int buttonState = NONE_PRESSED;
int lastReadState = NONE_PRESSED;
//Last time we started the debounce
long lastDebounceTime = 0;

//Set defaults
IndIOButtonPanel::IndIOButtonPanel(){
	_pin = A5;
	buttonsAnalogValue = 0;
	_debounceTime = 100;
}
//Use a different pin
IndIOButtonPanel::IndIOButtonPanel(int pin){
	_pin = pin;
	buttonsAnalogValue = 0;
	_debounceTime = 100;
}
//Set pin and debounce time
IndIOButtonPanel::IndIOButtonPanel(int pin, long debounceTime){
	_pin = pin;
	buttonsAnalogValue = 0;
	_debounceTime = 100;
	_debounceTime = debounceTime;
}
/**
*	Called to get the current button pressed state.  The state is only changed
*	after the debounce has passed.
*/
int IndIOButtonPanel::readButtonPanel(){
  //Read the current analog value
  buttonsAnalogValue = analogRead(_pin);
  
  //Analog values from Industruino samples
  if (buttonsAnalogValue>400 && buttonsAnalogValue< 700 ){
    readState = ENTER_PRESSED;
  }else if (buttonsAnalogValue>100 && buttonsAnalogValue<400){
    readState = UP_PRESSED;
  }else if (buttonsAnalogValue>700 && buttonsAnalogValue<1000 ){
    readState = DOWN_PRESSED;
  }else{
	readState = NONE_PRESSED;
  }
  //Reset the debounce if the last read state has changed.
  if(readState != lastReadState){
	  lastDebounceTime = millis();
  }
  
  //If more time has passed then _debounceTime, update the state if it is a 
  //different state.
  if(millis() - lastDebounceTime > _debounceTime){
	  if(readState != buttonState){
		  buttonState = readState;
	  }
  }
  //Update the last read state
  lastReadState = readState;
  return buttonState;
}