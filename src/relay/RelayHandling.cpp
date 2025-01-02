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
        // Turning off the relay seems to be causing some noise in the electronics which messes up the OLED display timing.
        // Instead of fixing that with proper electrical engineering knowledge I'm just adding a delay lol.
        delay(200);
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