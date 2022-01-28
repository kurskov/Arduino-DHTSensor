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

class DHTSensor {
    public:
        DHTSensor();
        int getTemp();
        int getHum();
};

#endif // _H_A83D8AAF_4F75_4E77_B9CF_CA4EA694DB35
