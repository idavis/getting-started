/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */
   
#ifndef _AZURE_CONFIG_H
#define _AZURE_CONFIG_H

typedef enum
{
    None          = 0, 
    WEP           = 1,
    WPA_PSK_TKIP  = 2,
    WPA2_PSK_AES  = 3
} WiFi_Mode;

// ----------------------------------------------------------------------------
// WiFi connection information
// ----------------------------------------------------------------------------
#define WIFI_SSID           "Other_5G"
#define WIFI_PASSWORD       "temptemp"
#define WIFI_MODE           WPA2_PSK_AES

// ----------------------------------------------------------------------------
// Azure IoT Hub Connection Transport
// Define this to use the nx client, otherwise MQTT
// ----------------------------------------------------------------------------
//#define USE_NX_CLIENT_PREVIEW

// ----------------------------------------------------------------------------
// Azure IoT Device information
// ----------------------------------------------------------------------------
#define IOT_HUB_HOSTNAME    "zentrum.azure-devices.net"
#define IOT_DEVICE_ID       "MySTMDevice"
#define IOT_PRIMARY_KEY     "1Vb4qjL037IaUZfFHpF2qczBPiEdFEPnqtl80TD/E6o="

#endif // _AZURE_CONFIG_H

