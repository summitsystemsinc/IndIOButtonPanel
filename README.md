# IndIOButtonPanel

Simple Arduino library for reading the button states on an Industruino.

## Installation

See: [Arduino Library docs](http://www.arduino.cc/en/guide/libraries#toc5)

Either download the zip of the repository and install through the Arduino IDE, or do a manual install with a git checkout.

## Usage
```arduino
IndIOButtonPanel btns;

int lastButton;
int currentButton;

void setup() {
    btns = IndIOButtonPanel();
    lastButton = NONE_PRESSED;
    currentButton = NONE_PRESSED;
}

void loop() {
    currentButton = btns.readButtonPanel();
    if(currentButton != lastButton){
        //Do something with the button press.
    }
}
```

### Variables
There are a couple of constants defined for help:
```c
const int ENTER_PRESSED = 1;
const int UP_PRESSED = 2;
const int DOWN_PRESSED = 3;
const int NONE_PRESSED = 0;
```
### Functions
```c
int readButtonPanel(); //Returns 0-4, noted above.
```
**NOTE** With the current logic, sometimes UP + DOWN yields an ENTER being pressed.

    
