#include "RelayHandling.h"

void RelayHandler::configureRelay()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    this->lastProcessTimeInMillisFromBoot = millis();
}

void RelayHandler::processSmokeMachineData(SmokeMachineData &smokeMachineData)
{
    smokeMachineData.remainingSmokeTimeInMillis = getNewRemainingSmokeTime(smokeMachineData.remainingSmokeTimeInMillis);

    if (smokeMachineData.remainingSmokeTimeInMillis > 0)
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
    }

    this->lastProcessTimeInMillisFromBoot = millis();
}

int RelayHandler::getNewRemainingSmokeTime(int remainingSmokeTimeInMillis)
{
    unsigned long elapsedTimeInMillis = millis() - this->lastProcessTimeInMillisFromBoot;

    remainingSmokeTimeInMillis -= elapsedTimeInMillis;

    if (remainingSmokeTimeInMillis < 0)
    {
        return 0;
    }

    return remainingSmokeTimeInMillis;
}