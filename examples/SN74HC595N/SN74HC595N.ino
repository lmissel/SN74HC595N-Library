/*
    SN74HC595N Example: LED Knight Rider

    This sketch demonstrates how to create a Knight Rider (K.I.T.T.) effect
    using LEDs controlled by SN74HC595N shift registers.

    The circuit:
    * Attach LEDs to each output pin of the shift register.

    Created 20 March 2024
    By lmissel

    http://github.com/lmissel/SN74HC595N
    https://www.tinkercad.com/things/lUhQzvDDboZ-74hc595-kitt
*/

#include <SN74HC595N.h>

// Pin Definitions
const uint8_t SER_PIN = 2;     // Serial Input
const uint8_t SRCLK_PIN = 3;   // Clock for the shift register
const uint8_t RCLK_PIN = 4;    // Clock for the register load operation
const uint8_t OE_PIN = 5;      // Output activation
const uint8_t SRCLR_PIN = 6;   // Shift register reset

// Number of Shift Registers
const uint8_t NUM_REGISTERS = 8;

// Create an instance of the shift register
SN74HC595N shiftRegister(SER_PIN, SRCLK_PIN, RCLK_PIN, OE_PIN, SRCLR_PIN, NUM_REGISTERS);

void setup() {
  // Begin communication with the shift register
  shiftRegister.begin();
}

void loop() {

  // Moving light pattern up
  for (int i = 0; i < 8; ++i) {
    // Turn on one LED
    shiftRegister.write(1 << (i % 8));
    delay(100); // Wait for 100 milliseconds
  }
  
  // Moving light pattern down
  for (int i = 7; i > 0; --i) {
    // Turn on one LED
    shiftRegister.write(1 << (i % 8));
    delay(100); // Wait for 100 milliseconds
  }
}
