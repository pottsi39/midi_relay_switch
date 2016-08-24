/*
    MIDI CC Light Show
    by Notes and Volts
    www.notesandvolts.com
*/

#include <MIDI.h>  // Add Midi Library

// Define labels for the 6 PWM pins
int Relay1 = 12;
int Relay2 = 11;
int Relay3 = 10;
int Relay4 = 9;
int Green1 = 4;
int Red1 = 5;
int Green2 = 6;
int Red2 = 7;
int Pow1 = 2;
int Pow2 = 3;



//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  pinMode (Red1, OUTPUT);
  pinMode (Red2, OUTPUT);
  pinMode (Green1, OUTPUT);
  pinMode (Green2, OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Pow1, OUTPUT);
  pinMode(Pow2, OUTPUT);
  //pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleControlChange(MyCCFunction); // This command tells the MIDI Library
  // the function you want to call when a Continuous Controller command
  // is received. In this case it's "MyCCFunction".
}

void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}

// MyCCFunction is the function that will be called by the Midi Library
// when a Continuous Controller message is received.
// It will be passed bytes for Channel, Controller Number, and Value
// It checks if the controller number is within the 22 to 27 range
// If it is, light up the corresponding LED with the PWM brightness equal to the Value byte
void MyCCFunction(byte channel, byte number, byte Value) {
  switch (number) {
    case 22:
      digitalWrite(Relay1, LOW);
      digitalWrite(Relay2, LOW);
      digitalWrite(Pow1, HIGH);
      digitalWrite(Pow2, HIGH);
      digitalWrite(Green1, HIGH);
      digitalWrite(Red1, LOW);
    
      break;
    case 23:
      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);
      digitalWrite(Pow1, HIGH);
      digitalWrite(Pow2, HIGH);
      digitalWrite(Green1, LOW);
      digitalWrite(Red1, HIGH);
      break;
      case 24:
      digitalWrite(Relay3, LOW);
      digitalWrite(Relay4, LOW);
      digitalWrite(Pow1, HIGH);
      digitalWrite(Pow2, HIGH);
      digitalWrite(Green2, HIGH);
      digitalWrite(Red2, LOW);
      break;
      case 25:
      digitalWrite(Relay3, HIGH);
      digitalWrite(Relay4, HIGH);
      digitalWrite(Pow1, HIGH);
      digitalWrite(Pow2, HIGH);
      digitalWrite(Green2, LOW);
      digitalWrite(Red2, HIGH);
      break;

  }
}
