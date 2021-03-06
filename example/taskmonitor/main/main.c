/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "taskmonitor.h"
#include "esp_log.h"

void app_main(void)
{
    ESP_LOGI("MAIN","Hello world!\n");

    taskMonitorInit();
    taskMonitorStart();

    for (int i = 50; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    ESP_LOGI("MAIN","Restarting now.\n");
    esp_restart();
}