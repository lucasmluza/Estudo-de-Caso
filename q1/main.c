/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Task prototypes */
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{

    xTaskCreate(&vTask1, "Task 1", 16384, NULL, 2, NULL);
    xTaskCreate(&vTask2, "Task 2", 16384, NULL, 2, NULL);

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
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}