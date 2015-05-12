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

#ifndef IndIOButtonPanel_h
#define IndIOButtonPanel_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

//Value returned if Enter is pressed
const int ENTER_PRESSED = 1;
//Value returned if Up is pressed
const int UP_PRESSED = 2;
//Value returned if Down is pressed
const int DOWN_PRESSED = 3;
//Value returned if Nothing is pressed
const int NONE_PRESSED = 0;
/**
*	Class for interpreting button presses on the Industruino
*	
*	Create an instance of the class, then call readButtonPanel to get the current pressed button
*/
class IndIOButtonPanel{
	public: 
		IndIOButtonPanel();
		IndIOButtonPanel(int pin);
		IndIOButtonPanel(int pin, long debounceTime);
		int readButtonPanel();
		int buttonsAnalogValue;
	private:
		//Pin used for reading the screen
		int _pin;
		//Time that must elapse for a button to be "read"
		long _debounceTime;
};
#endif