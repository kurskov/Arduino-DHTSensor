/*
    DHT Sensor

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
    GitHub: GitHub: https://github.com/kurskov/Arduino-DHTSensor
    
    Version: 0.0.0
*/

// Include guard
#ifndef _H_A83D8AAF_4F75_4E77_B9CF_CA4EA694DB35
#define _H_A83D8AAF_4F75_4E77_B9CF_CA4EA694DB35

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

// Bitwise operations
#define __setBit(byte, bit) ((byte) |= (1UL << (bit)))
#define __clrBit(byte, bit) ((byte) &= ~(1UL << (bit)))
#define __isSet(byte, bit) (((byte) & (1UL << (bit))) >> (bit))

// Temperature units
#define DHT_UNITS_C 1 // Celsius 
#define DHT_UNITS_F 0 // Fahrenheit 

// DHT Status
#define DHT_STATUS_OK 0
#define DHT_ERROR_INIT_0 1
#define DHT_ERROR_INIT_1 2
#define DHT_READ_TIMEOUT 3
#define DHT_ERROR_CHECKSUM 4

class DHTSensor {
    public:
        DHTSensor(uint8_t pin = 2);
        float getTemp(bool units = DHT_UNITS_C);
        float getHum();
        void setPin(uint8_t pin);

    private:
        uint8_t _pin;
        uint8_t _data[5];
        
        uint8_t readData();
};

#endif // _H_A83D8AAF_4F75_4E77_B9CF_CA4EA694DB35
