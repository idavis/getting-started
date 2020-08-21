/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */
   
#ifndef _AZURE_CONFIG_H
#define _AZURE_CONFIG_H

#include "wwd_constants.h"

// ----------------------------------------------------------------------------
// WiFi connection information
// ----------------------------------------------------------------------------
#define WIFI_SSID           "Other_5G"
#define WIFI_PASSWORD       "temptemp"

// WIFI Security as defined in lib/wiced_sdk/43xxx_Wi-Fi/wwd_constants.h
#define WIFI_SECURITY       WICED_SECURITY_WPA2_MIXED_PSK

// ----------------------------------------------------------------------------
// Azure IoT Hub Connection Transport
// Define this to use the nx client, otherwise MQTT
// ----------------------------------------------------------------------------
// #define USE_NX_CLIENT_PREVIEW

// ----------------------------------------------------------------------------
// Azure IoT Device information
// ----------------------------------------------------------------------------
#define IOT_HUB_HOSTNAME    "zentrum.azure-devices.net"
#define IOT_DEVICE_ID       "MySTMDevice"
#define IOT_PRIMARY_KEY     "1Vb4qjL037IaUZfFHpF2qczBPiEdFEPnqtl80TD/E6o="

#endif // _AZURE_CONFIG_H
