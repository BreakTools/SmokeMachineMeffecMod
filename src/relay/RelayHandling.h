#ifndef RELAYHANDLING_H
#define RELAYHANDLING_H

#include <Arduino.h>

#include "Config.h"
#include "DataTypes.h"

class RelayHandler
{
public:
    void configureRelay();
    void processSmokeMachineData(SmokeMachineData &smokeMachineData);

private:
    unsigned long lastProcessTimeInMillisFromBoot;

    int getNewRemainingSmokeTime(int remainingSmokeTimeInMillis);
};

#endif
