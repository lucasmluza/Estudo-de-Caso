/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Global variable resource */
int resource = 0;

/* Create the Semaphore/Mutex handler */
SemaphoreHandle_t mutex;

/* Task prototypes */
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{

    printf("Starting application\r\n");

    xTaskCreate(&vTask1, "Task 1", 16384, NULL, 1, NULL);
    xTaskCreate(&vTask2, "Task 2", 16384, NULL, 1, NULL);

    mutex = xSemaphoreCreateMutex();

    vTaskStartScheduler();

    /* Execution will only reach here if there was not enough FreeRTOS heap memory
    remaining for the idle task to be created. */
    for (;;)
        ;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        if (xSemaphoreTake(mutex, (TickType_t)portMAX_DELAY) == pdTRUE)
        {
            resource++;
            printf("Task 1 : %d\r\n", resource);
            xSemaphoreGive(mutex);
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        if (xSemaphoreTake(mutex, (TickType_t)portMAX_DELAY) == pdTRUE)
        {
            resource--;
            printf("Task 2 : %d\r\n", resource);
            xSemaphoreGive(mutex);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}