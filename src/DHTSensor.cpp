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
        return temp * 9 / 5 +32; // Celsius to fahrenheit 
    }
}

float DHTSensor::getHum() {
    //
    float hum = 0;

    return hum;
}

void setPin(uint8_t pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWhite(_pin, HIGH);
}

uint8_t readData() {
    uint8_t testLine;
    
    //
    digitalWrite(_pin, LOW);
    delay(18);
    digitalWrite(_pin, HIGH);
    //
    delayMicroseconds(30);
    //
    pinMode(_pin, INPUT);
    //
    delayMicroseconds(40);
    
    if ( digitalRead(_pin) ) {
        return DHT_ERROR_INIT_0;
    }

    delayMicroseconds(80);

    if ( !digitalRead(_pin) ) {
        return DHT_ERROR_INIT_1;
    }

    

    return DHT_STATUS_OK
}