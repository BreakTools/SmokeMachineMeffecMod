#include "MeffecHandling.h"

void MeffecHandler::configureMeffec(void (*onSmokeTimingReceived)(int))
{
    this->onSmokeTimingReceived = (void (*)(int))onSmokeTimingReceived;
    this->websocketClient.onMessage([this](WebsocketsMessage message)
                                    { this->onWebSocketMessageReceived(message); });
    this->websocketClient.onEvent([this](WebsocketsEvent event, String data)
                                  { this->onWebSocketEventOccured(event, data); });
}

bool MeffecHandler::isConnected()
{
    return this->connectedToServer;
}

void MeffecHandler::processMeffecData(bool isConnectedToWiFi)
{
    if (!isConnectedToWiFi)
    {
        return;
    }

    if (!this->connectedToServer)
    {
        this->connectToWebSocketServer();
        return;
    }

    this->websocketClient.poll();
}

void MeffecHandler::connectToWebSocketServer()
{
    String tokenedServerUrl = String(MEFFEC_SERVER_URL) + "/?token=$" + String(MEFFEC_SERVER_TOKEN);
    if (!this->websocketClient.connect(tokenedServerUrl))
    {
        return;
    }

    this->connectedToServer = true;
    this->websocketClient.send(getAuthenticationMessage());
}

String MeffecHandler::getAuthenticationMessage()
{
    JsonDocument authenticationMessageDocument;

    authenticationMessageDocument["type"] = "authentication";
    JsonObject data = authenticationMessageDocument["data"].to<JsonObject>();
    data["type"] = "device";
    data["name"] = "Smoke Machine V2";

    String authenticationMessage;
    serializeJson(authenticationMessageDocument, authenticationMessage);

    return authenticationMessage;
}

void MeffecHandler::onWebSocketMessageReceived(WebsocketsMessage message)
{
    JsonDocument parsedMeffecMessage;
    DeserializationError deserializationError = deserializeJson(parsedMeffecMessage, message.data());

    if (deserializationError)
    {
        return;
    }

    String messageType = parsedMeffecMessage["type"];
    if (messageType != "device_action")
    {
        return;
    }

    int smokeTimeInMillis = parsedMeffecMessage["data"]["smoke_time_in_millis"];
    this->onSmokeTimingReceived(smokeTimeInMillis);
}

void MeffecHandler::onWebSocketEventOccured(WebsocketsEvent event, String data)
{
    if (event == WebsocketsEvent::ConnectionOpened)
    {
        this->connectedToServer = true;
    }

    if (event == WebsocketsEvent::ConnectionClosed)
    {
        this->connectedToServer = false;
    }
}
