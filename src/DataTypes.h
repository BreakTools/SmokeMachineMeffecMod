#ifndef DATATYPES_H
#define DATATYPES_H

struct SmokeMachineData
{
    int remainingSmokeTimeInMillis = 0;
    bool isConnectedToWiFi = false;
    bool isConnectedToMeffec = false;

    SmokeMachineData() = default;

    bool operator==(const SmokeMachineData &other) const
    {
        return remainingSmokeTimeInMillis == other.remainingSmokeTimeInMillis &&
               isConnectedToWiFi == other.isConnectedToWiFi &&
               isConnectedToMeffec == other.isConnectedToMeffec;
    }

    bool operator!=(const SmokeMachineData &other) const
    {
        return !(*this == other);
    }
};

#endif
