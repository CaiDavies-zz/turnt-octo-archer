/*
RPM and Speed via reed switch.
Based on state change example and blink withought delay.
 http://arduino.cc/en/Tutorial/ButtonStateChange
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
This code is junk.
This really needs to trigger an interupt. That is beyond me currently.
You have been warned.
Reed switch may require hardware debouncing.
*/

// Constants.
const int switchPin = 2;        // Set the pin used for reed switch.
const float circ = 69.12;       // Circumference of wheel = DIAM * PI in inches
const int red = 4;
const int green = 7;
int redButtonState = 1;
int greenButtonState = 1;
int lastRedButtonState = 1;
int lastGreenButtonState = 1;
int debounceCount = 20;
long timeOfLastButton = 0;

int currentReading=1;
int lastReading = 1;

// Variables.
unsigned int switchCounter = 0;     // Rotation counter.
int switchState = 0;                // State of reed switch.
int lastSwitchState = 0;            //last state of switch.
unsigned long lastMicros = 0;       // Last report HIGH
unsigned long currentMicros = 0;    // Current report HIGH         
unsigned long difMicros = 0;        // Difference
float RPM = 0;                      // RPM in Float.
float MPH = 0;                      // Miles Per Hour.


void setup() {
  pinMode(switchPin, INPUT);
  pinMode(red, INPUT_PULLUP);
  pinMode(green, INPUT_PULLUP);
  Serial.begin(9600);
}

// Enter loop.

void loop() {

  switchState = digitalRead(switchPin);
  redButtonState = digitalRead(red);
  greenButtonState = digitalRead(green);
  unsigned long currentTime = millis();

  if (switchState != lastSwitchState) {
   
    if (switchState == HIGH) {
    switchCounter++;
    currentMicros = micros();
    difMicros = currentMicros - lastMicros;
    RPM = 60000000.0 / difMicros;
    MPH = (((RPM * circ) / 12) / 5280) * 60;
    Serial.println(MPH/10);
  }
  }
    
  if(redButtonState != lastRedButtonState){
    
    if (currentTime - timeOfLastButton > debounceCount){
    
    Serial.println("red");
    lastRedButtonState = redButtonState;
        timeOfLastButton = currentTime;
    }
      
}

if(greenButtonState != lastGreenButtonState){
    
    if (currentTime - timeOfLastButton > debounceCount){
    
    Serial.println("green");
    lastGreenButtonState = greenButtonState;
        timeOfLastButton = currentTime;
    }
      
}

lastGreenButtonState = greenButtonState;  
lastRedButtonState = redButtonState;

lastSwitchState = switchState;
lastMicros = currentMicros;
 
}

