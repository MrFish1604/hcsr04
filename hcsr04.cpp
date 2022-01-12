#include "hcsr04.h"

HCSR04::HCSR04(const uint8_t trig, const uint8_t echo): _echo(echo), _trig(trig)
{
    pinMode(_echo, INPUT);
    pinMode(_trig, OUTPUT);
}

void HCSR04::trig()
{
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);
}

float HCSR04::getToF()
{
    trig();
    return pulseIn(_echo, HIGH);
}

float HCSR04::getDist()
{
    return getToF()/59f;
}

float HCSR04::getDist2(float slope, float offset)
{
    return slope * getToF() + offset;
}