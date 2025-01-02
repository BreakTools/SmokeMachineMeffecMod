#include "OledHandling.h"

OledHandler::OledHandler()
    : oledDisplay(OLED_WIDTH, OLED_HEIGHT, &Wire, -1) {}

void OledHandler::configureOledDisplay()
{
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);
    oledDisplay.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS);
    oledDisplay.setTextSize(2);
    oledDisplay.setTextColor(WHITE);
    oledDisplay.clearDisplay();
    displayBootScreen();
}

void OledHandler::displayBootScreen()
{
    if (DISABLE_BOOT_ANIMATION)
    {
        return;
    }

    drawFullscreenImage(MEFFEC_FULLSCREEN_ICON);
    delay(2000);
    drawFullscreenImage(MEFFEC_FULLSCREEN_BANNER);
    delay(2000);
}

void OledHandler::displaySmokeMachineData(SmokeMachineData smokeMachineData)
{
    if (!hasSmokeMachineDataChanged(smokeMachineData))
    {
        return;
    }

    oledDisplay.clearDisplay();

    drawTopSectionBase();
    drawWifiStatusIcon(smokeMachineData.isConnectedToWiFi);
    drawMeffecStatusIcon(smokeMachineData.isConnectedToMeffec);
    drawStatusText(smokeMachineData);

    oledDisplay.display();
}

bool OledHandler::hasSmokeMachineDataChanged(SmokeMachineData smokeMachineData)
{
    if (lastReceivedSmokeMachineData != smokeMachineData)
    {
        lastReceivedSmokeMachineData = smokeMachineData;
        return true;
    }

    lastReceivedSmokeMachineData = smokeMachineData;
    return false;
}

void OledHandler::drawFullscreenImage(const unsigned char imageByteArray[])
{
    oledDisplay.clearDisplay();
    oledDisplay.drawBitmap(0, 0, imageByteArray, OLED_WIDTH, OLED_HEIGHT, WHITE);
    oledDisplay.display();
}

void OledHandler::drawTopSectionBase()
{
    oledDisplay.drawBitmap(8, 2, MEFFEC_BANNER_SMALL, 61, 16, WHITE);
    oledDisplay.drawLine(0, 17, OLED_WIDTH, 17, WHITE);
}

void OledHandler::drawWifiStatusIcon(bool isConnectedToWifi)
{
    if (isConnectedToWifi)
    {
        oledDisplay.drawBitmap(85, 0, WIFI_WORKING, 16, 16, WHITE);
    }
    else
    {
        oledDisplay.drawBitmap(85, 0, WIFI_PROBLEM, 16, 16, WHITE);
    }
}

void OledHandler::drawMeffecStatusIcon(bool isConnectedToMeffec)
{
    if (isConnectedToMeffec)
    {
        oledDisplay.drawBitmap(104, 0, MEFFEC_WORKING, 16, 16, WHITE);
    }
    else
    {
        oledDisplay.drawBitmap(104, 0, MEFFEC_PROBLEM, 16, 16, WHITE);
    }
}

void OledHandler::drawStatusText(SmokeMachineData smokeMachineData)
{

    if (!smokeMachineData.isConnectedToWiFi)
    {
        drawHorizontallyCenteredText("WiFi", 26);
        drawHorizontallyCenteredText("issue!", 43);
        return;
    }

    if (!smokeMachineData.isConnectedToMeffec)
    {
        drawHorizontallyCenteredText("Meffec", 26);
        drawHorizontallyCenteredText("issue!", 43);
        return;
    }

    if (smokeMachineData.remainingSmokeTimeInMillis > 0)
    {
        float remainingTimeInSeconds = smokeMachineData.remainingSmokeTimeInMillis / 1000.0;
        String smokeTimeText = String(remainingTimeInSeconds, 1) + String("s");

        drawHorizontallyCenteredText("Smoke:", 26);
        drawHorizontallyCenteredText(smokeTimeText, 43);
        return;
    }

    oledDisplay.setCursor(36, 30);
    drawHorizontallyCenteredText("Ready!", 34);
}

void OledHandler::drawHorizontallyCenteredText(String text, int yPosition)
{
    int16_t upperLeftCornerX, upperLeftCornerY; // Unused but needed for getTextBounds
    uint16_t textBoundWidth, textBoundHeight;
    oledDisplay.getTextBounds(text, 0, 0, &upperLeftCornerX, &upperLeftCornerY, &textBoundWidth, &textBoundHeight);
    int16_t horizontallyCenteredXPosition = (OLED_WIDTH - textBoundWidth) / 2;

    oledDisplay.setCursor(horizontallyCenteredXPosition, yPosition);
    oledDisplay.println(text);
}