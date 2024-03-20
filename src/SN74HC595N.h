#ifndef SN74HC595N_h
#define SN74HC595N_h

#include <Arduino.h>

class SN74HC595N {
private:
    uint8_t _serPin;       // Serieller Eingang (SER_IN)
    uint8_t _srclkPin;     // Takt für das Schieberegister
    uint8_t _rclkPin;      // Takt für die Registerladeoperation
    uint8_t _oePin;        // Ausgangsaktivierung
    uint8_t _srclrPin;     // Zurücksetzen des Schieberegisters
    uint8_t _numRegisters; // Anzahl der Schieberegister
public:
    SN74HC595N(uint8_t serPin, uint8_t srclkPin, uint8_t rclkPin, uint8_t oePin, uint8_t srclrPin, uint8_t numRegisters = 1);

    void begin();
    void write(uint8_t data);
    void clear();
    void enableOutputs();
    void disableOutputs();
};

#endif