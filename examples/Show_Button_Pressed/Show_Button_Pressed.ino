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

//Glyph width, plus the separator
static const int GLYPTH_WIDTH = 6;

int lastButton;
int currentButton;

int enterCount = 0;
int upCount = 0;
int downCount = 0;

IndIOButtonPanel btns;

void setup() {
  btns = IndIOButtonPanel();
  lastButton = NONE_PRESSED;
  currentButton = NONE_PRESSED;
  lcd.begin();
  screenWrite(NONE_PRESSED);
  
  lcd.setCursor(0,2);
  lcd.print("ENTER: ");
  lcd.setCursor(0,3);
  lcd.print("UP: ");
  lcd.setCursor(0,4);
  lcd.print("DOWN: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = btns.readButtonPanel();  

  if(currentButton != lastButton){
    lcd.setCursor(0,0);
    lcd.print("               ");
    screenWrite(currentButton);
    lastButton = currentButton;
  }
}

void screenWrite(int btn){
  lcd.setCursor(0,0);
  switch(currentButton){
      case ENTER_PRESSED:
        lcd.print("ENTER");
        enterCount++;
        lcd.setCursor(GLYPTH_WIDTH*7,2);
        lcd.print(enterCount);
        break;
      case UP_PRESSED:
        lcd.print("UP");
        upCount++;
        lcd.setCursor(GLYPTH_WIDTH*4,3);
        lcd.print(upCount);
        break;
      case DOWN_PRESSED:
        lcd.print("DOWN");
        downCount++;
        lcd.setCursor(GLYPTH_WIDTH*6,4);
        lcd.print(downCount);
        break;
      default:
        lcd.print("NOTHING PRESSED");
    }
}
