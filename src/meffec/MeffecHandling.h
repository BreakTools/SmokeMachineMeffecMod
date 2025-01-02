#ifndef MEFFECHANDLING_H
#define MEFFECHANDLING_H

#include <Arduino.h>
#include <ArduinoWebsockets.h>
#include <ArduinoJson.h>

#include "Config.h"

using namespace websockets;

class MeffecHandler
{
public:
    void configureMeffec(void (*onSmokeTimingReceived)(int));
    bool isConnected();
    void processMeffecData(bool isConnectedToWiFi);

private:
    void (*onSmokeTimingReceived)(int);
    bool connectedToServer = false;
    WebsocketsClient websocketClient;

    void connectToWebSocketServer();
    String getAuthenticationMessage();
    void onWebSocketMessageReceived(WebsocketsMessage message);
    void onWebSocketEventOccured(WebsocketsEvent event, String data);
};

#endif