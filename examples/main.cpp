#include <stdio.h>
#include "main.h"

void app_main(void) {

    // Inicialización de la conexión Wi-Fi
    if (wifi_init() != ESP_OK) {
        // En caso de error, se puede agregar algún código aquí para manejar la situación
        return;
    }

    // Aquí puedes agregar cualquier otra funcionalidad que necesites
}
