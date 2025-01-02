#include <Arduino.h>

#include "Config.h"
#include "DataTypes.h"
#include "oled/OledHandling.h"
#include "relay/RelayHandling.h"
#include "wifi/WiFiHandling.h"
#include "meffec/MeffecHandling.h"

OledHandler oledHandler;
WifiHandler wifiHandler;
MeffecHandler meffecHandler;
RelayHandler relayHandler;

SmokeMachineData smokeMachineData;

void onSmokeTimingReceived(int smokeTimeInMillis)
{
    smokeMachineData.remainingSmokeTimeInMillis = smokeTimeInMillis;
}

void setup()
{
    relayHandler.configureRelay();
    wifiHandler.configureWiFi();
    meffecHandler.configureMeffec(onSmokeTimingReceived);
    oledHandler.configureOledDisplay();
}

void loop()
{
    smokeMachineData.isConnectedToWiFi = wifiHandler.isConnected();
    meffecHandler.processMeffecData(smokeMachineData.isConnectedToWiFi);
    smokeMachineData.isConnectedToMeffec = meffecHandler.isConnected();
    relayHandler.processSmokeMachineData(smokeMachineData);
    oledHandler.displaySmokeMachineData(smokeMachineData);
}
