#include "wifi.h"

// Datos de la red Wi-Fi
#define WIFI_SSID "nombre_de_la_red"
#define WIFI_PASS "contraseña_de_la_red"

esp_err_t wifi_init() {
    

    // Configuración de la conexión Wi-Fi
    wifi_config_t wifi_config = {};
    strcpy((char *) wifi_config.sta.ssid, WIFI_SSID);
    strcpy((char *) wifi_config.sta.password, WIFI_PASS);
    wifi_config.sta.bssid_set = false;

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    // Inicialización del controlador de Wi-Fi
    esp_err_t ret = esp_wifi_init(&cfg);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al inicializar el controlador de Wi-Fi: %s", esp_err_to_name(ret));
        return ret;
    }

    // Configuración del modo de operación del controlador de Wi-Fi
    ret = esp_wifi_set_mode(WIFI_MODE_STA);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al configurar el modo de operación del controlador de Wi-Fi: %s", esp_err_to_name(ret));
        return ret;
    }

    // Configuración de la conexión del controlador de Wi-Fi
    ret = esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al configurar la conexión del controlador de Wi-Fi: %s", esp_err_to_name(ret));
        return ret;
    }

    // Inicio del controlador de Wi-Fi
    ret = esp_wifi_start();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al iniciar el controlador de Wi-Fi: %s", esp_err_to_name(ret));
        return ret;
    }

    // Conexión a la red Wi-Fi
    ret = esp_wifi_connect();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al conectar a la red Wi-Fi: %s", esp_err_to_name(ret));
        return ret;
    }

    return ESP_OK;
}
