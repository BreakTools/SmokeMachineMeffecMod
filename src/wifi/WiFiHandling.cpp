#include "WiFiHandling.h"

void WifiHandler::configureWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

bool WifiHandler::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}