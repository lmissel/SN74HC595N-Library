#include "SN74HC595N.h"

SN74HC595N::SN74HC595N(uint8_t serPin, uint8_t srclkPin, uint8_t rclkPin, uint8_t oePin, uint8_t srclrPin, uint8_t numRegisters) {
    _serPin = serPin;
    _srclkPin = srclkPin;
    _rclkPin = rclkPin;
    _oePin = oePin;
    _srclrPin = srclrPin;
    _numRegisters = numRegisters;
}

void SN74HC595N::begin() {
    pinMode(_serPin, OUTPUT);
    pinMode(_srclkPin, OUTPUT);
    pinMode(_rclkPin, OUTPUT);
    pinMode(_oePin, OUTPUT);
    pinMode(_srclrPin, OUTPUT);

    digitalWrite(_oePin, LOW); // HIGH deaktiviert die Ausgänge
    digitalWrite(_srclrPin, HIGH); // Setze das Schieberegister zurück (HIGH bedeutet deaktiviert)
}

void SN74HC595N::write(uint8_t data) {
    digitalWrite(_rclkPin, LOW); // Setze RCLK auf LOW, um den parallelen Schreibvorgang zu beginnen
    shiftOut(_serPin, _srclkPin, MSBFIRST, data); // Schreibe die Daten seriell in das Schieberegister
    digitalWrite(_rclkPin, HIGH); // Ladeoperation ausführen, indem RCLK auf HIGH gesetzt wird
}

void SN74HC595N::clear() {
    digitalWrite(_srclrPin, LOW); // Setze das Schieberegister zurück (LOW bedeutet aktiviert)
    digitalWrite(_srclrPin, HIGH); // Deaktiviere das Zurücksetzen (HIGH)
}

void SN74HC595N::enableOutputs() {
    digitalWrite(_oePin, LOW); // LOW aktiviert die Ausgänge
}

void SN74HC595N::disableOutputs() {
    digitalWrite(_oePin, HIGH); // HIGH deaktiviert die Ausgänge
}