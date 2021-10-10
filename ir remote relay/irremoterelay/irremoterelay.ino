/*
  IR Receiver Demonstration 3
  IR-Rcv-Demo3.ino
  Control LED's using Unused IR Remote keys

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 9;
// Define LED pin constants
const int relay1 = 13;
const int relay2 = 8;
const int relay3 = 10;
const int relay4 = 11;
// Define integer to remember toggle state
int togglestate1 = 0;
int togglestate2 = 0;
int togglestate3 = 0;
int togglestate4 = 0;
int togglestateall = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.begin(9600);
  Serial.println("results.value, HEX");
}


void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {

      case 0x807F8877: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate1 == 0) {
          digitalWrite(relay1, HIGH);
          togglestate1 = 1;
          togglestateall = 1;
        }
        else {
          digitalWrite(relay1, LOW);
          togglestate1 = 0;
          togglestateall = 0;
        }
        break;

      case 0x807F48B7: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate2 == 0) {
          digitalWrite(relay2, HIGH);
          togglestate2 = 1;
          togglestateall = 1;
        }
        else {
          digitalWrite(relay2, LOW);
          togglestate2 = 0;
          togglestateall = 0;
        }
        break;

      case 0x807FC837: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate3 == 0) {
          digitalWrite(relay3, HIGH);
          togglestate3 = 1;
          togglestateall = 1;
        }
        else {
          digitalWrite(relay3, LOW);
          togglestate3 = 0;
          togglestateall = 0;
        }
        break;

      case 0xFFD12E: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate4 == 0) {
          digitalWrite(relay4, HIGH);
          togglestate4 = 1;
          togglestateall = 1;
        }
        else {
          digitalWrite(relay4, LOW);
          togglestate4 = 0;
          togglestateall = 0;
        }
        break;

      case 0x807F00FF: //Yellow Keypad Button
        // Toggle LED On or Off

        digitalWrite(relay1, LOW);
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, LOW);
        togglestateall = 0;

        break;


    }
    irrecv.resume();
  }

}
