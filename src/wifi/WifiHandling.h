#ifndef WIFIHANDLING_H
#define WIFIHANDLING_H

#include <Arduino.h>
#include <WiFi.h>

#include "Config.h"

class WifiHandler
{
public:
    void configureWiFi();
    bool isConnected();
};

#endif
