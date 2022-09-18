#ifndef HCSR04_H
#define HCSR04_H

#include <Arduino.h>

#define SLOPE 0.017     // From experimentation
#define OFFSET -0.163   // Do your own

class HCSR04
{
public:
    HCSR04(const uint8_t trig, const uint8_t echo);
    void begin();
    void trig();
    float getToF();
    float getDist();
    float getDist2(float slope=SLOPE, float offset=OFFSET);
private:
    uint8_t _echo, _trig;
};

#endif
