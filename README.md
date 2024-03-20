# SN74HC595N-Library
 
The SN74HC595N is an output shift register with parallel input and serial input. It is often used to control several outputs with one microcontroller.
  
## SN74HC595N:
Here is a basic overview of the SN74HC595N and how it can be used:
 - 8-bit parallel-to-serial shift registers.
 - Parallel inputs and serial outputs.
 - Expanding the digital outputs of a microcontroller.
 
PINs:
 - **VCC**: Supply voltage (normally 5V).
 - **GND**: Ground.
 - **SER (Serial Input)**: Serial input.
 - **SRCLK (Shift Register Clock)**: Clock for the shift register.
 - **RCLK (Register Clock)**: Clock for the register load operation.
 - **OE (Output Enable)**: Output enable (normally LOW to enable).
 - **SRCLR (Shift Register Clear)**: Shift register reset (normally HIGH to enable).
 - **Qn (Serial Output)**: Serial outputs (Q0 to Q7).

## Installation
The Arduino environment can be extended through the use of libraries, just like most programming platforms. Libraries provide extra functionality for use in sketches, e.g. working with hardware or manipulating data. To use a library in a sketch, select it from ***Sketch > Import Library***.

A number of libraries come installed with the IDE, but you can also download or create your own. See [these instructions](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/) for details on installing libraries. There is also a [tutorial on writing your own libraries](https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/). See the [API Style Guide](https://docs.arduino.cc/learn/contributions/arduino-library-style-guide/) for information on making a good Arduino-style API for your library.

## Usage
The example sketch, which uses the `SN74HC595N` library to generate a simple running light pattern on LEDs with an 8-bit shift register, demonstrates the simple use of the library.

```cpp
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

// Number of Registers
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
  
```

### Circuit view

![Circuit view](/media/74HC595.png "SN74HC595N Example")

Simulate the code on thinkercad! Link: https://www.tinkercad.com/things/lUhQzvDDboZ-74hc595-kitt

### List of components
|Name|Quantity|Component|
|---|---|---|
|U1|1|Arduino Uno R3|
|U2|1|SN74HC595N|
|R1, R2, R3, R4, R5, R6, R7, R8|8|500 Ohm resistor|
|D1, D2, D3, D4, D5, D6, D7, D8|8|Red LED|

### Notes
- Make sure you adjust the pin numbers according to your actual wiring.
- Note that you need to consider the wiring of OE and SRCLR as their functions may e different from the manufacturer. In this example, they are assumed to be active high (HIGH) and active low (LOW) respectively.
- This is just a basic example. You can extend the functionality of the SN74HC595N according to your requirements.

## Changelog

|Version|State|Comment|
|---|---|---|
|1.0.0.0|done|Initial programming of the library.|

## Notes
The library documentation is still under construction. It will soon be available in German and English.