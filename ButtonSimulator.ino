/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;
int pushCount = 0;
int currentRunningState = 0;
unsigned long time;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);  
  Serial.begin(9600);  
}

void loop(){

  unsigned long  tmpTime = millis();
  //  Serial.println(tmpTime);
  if((tmpTime - time) < 30){
    return;
  }
  time = tmpTime;
//  Serial.write(time);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {  
    // turn LED on:    


    if(buttonState != lastButtonState){
      if(currentRunningState == 0){
        currentRunningState = 1;
        digitalWrite(ledPin, HIGH);
        Serial.println("[btn002,on]");
//        Serial.println("start running...");   
      }
      else{
        currentRunningState = 0;
        digitalWrite(ledPin, LOW);  
         Serial.println("[btn002,off]");
//        Serial.println("end running...");   
      }

      //prints time since program started
//      Serial.print("high   ");
      pushCount ++;
//      Serial.println(pushCount);
      lastButtonState=buttonState;
    }
  } 
  else {
    // turn LED off:
    //    digitalWrite(ledPin, LOW); 
    if(buttonState != lastButtonState){
      //      Serial.println("low");
      lastButtonState=buttonState;
    }

  }
  //  delay(1000);
}


















