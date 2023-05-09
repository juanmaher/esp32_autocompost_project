#ifndef WIFI_H
#define WIFI_H

#include <string.h>
#include "esp_wifi.h"
#include "esp_log.h"

extern const char *TAG;

esp_err_t wifi_init();

#endif
