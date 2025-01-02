#ifndef OLEDHANDLING_H
#define OLEDHANDLING_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>

#include "ImageByteArrays.h"
#include "Config.h"
#include "DataTypes.h"

class OledHandler
{
public:
    OledHandler();
    void configureOledDisplay();
    void displaySmokeMachineData(SmokeMachineData smokeMachineData);

private:
    Adafruit_SSD1306 oledDisplay;
    SmokeMachineData lastReceivedSmokeMachineData;

    void displayBootScreen();
    void drawFullscreenImage(const unsigned char imageByteArray[]);
    bool hasSmokeMachineDataChanged(SmokeMachineData smokeMachineData);
    void drawTopSectionBase();
    void drawWifiStatusIcon(bool isConnectedToWifi);
    void drawMeffecStatusIcon(bool isConnectedToMeffec);
    void drawStatusText(SmokeMachineData smokeMachineData);
    void drawHorizontallyCenteredText(String text, int yPosition);
};

#endif
