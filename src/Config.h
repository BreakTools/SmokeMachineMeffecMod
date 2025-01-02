#ifndef CONFIG_H
#define CONFIG_H

// WiFi configuration
#define WIFI_SSID "yourssid"
#define WIFI_PASSWORD "yourpassword"

// Meffec configuration
#define MEFFEC_SERVER_URL "ws://yourmeffecurl.com"
#define MEFFEC_SERVER_TOKEN "yourmeffectoken"

// Pin configuration
#define RELAY_PIN 9
#define OLED_SCL_PIN 0
#define OLED_SDA_PIN 1

// OLED configuration
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_I2C_ADDRESS 0x3C

// Development options
#define DISABLE_BOOT_ANIMATION 0

#endif
