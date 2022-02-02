/*
    See DHTSensor.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "DHTSensor.h"

// Constructor

DHTSensor::DHTSensor(uint8_t pin) {
    //
    setPin(pin);
}

float DHTSensor::getTemp(bool units) {
    //
    float temp = 0;
    if (units) {
        return temp;
    } else {
        return temp * 1.8 + 32; // Celsius to fahrenheit 
    }
}

float DHTSensor::getHum() {
    //
    float hum = 0;

    return hum;
}

void DHTSensor::setPin(uint8_t pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWhite(_pin, HIGH);
}

uint8_t DHTSensor::readData() {
    uint8_t testLine;

    // Empties last data
    for (uint8_t i = 0; i < 5; i++) {
        _data[i] = 0;
    }
    
    // Send out start signal
    // LOW > 18 ms, HIGH 20-40 us.
    digitalWrite(_pin, LOW);
    delay(18);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(30);
    
    // Set pin as input 
    // and delay half of first response signal.
    pinMode(_pin, INPUT);
    delayMicroseconds(40);
    // Check 0.
    if ( digitalRead(_pin) ) {
        return DHT_ERROR_INIT_0;
    }
    // delay to half of second response signal.
    delayMicroseconds(80);
    // Check 1.
    if ( !digitalRead(_pin) ) {
        return DHT_ERROR_INIT_1;
    }
    
    // Data reception 


    return DHT_STATUS_OK
}