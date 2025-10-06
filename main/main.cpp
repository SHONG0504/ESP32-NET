#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C"
{
    void app_main(void);
}

void print_task(void *args)
{
    uint32_t a = 0;
    for (;;)
    {
        ESP_LOGI("PRINT", "Hello %d", a++);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main(void)
{
    xTaskCreate(&print_task, "PRINT", 2048, NULL, 5, NULL);
}
