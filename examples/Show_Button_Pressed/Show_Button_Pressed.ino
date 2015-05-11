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


