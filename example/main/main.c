#include <stdio.h>

#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "logger.h"
static const char *TAG = "main";

void app_main(void)
{
    int a = 5;
    float pi = 3.141592f;
    char *str = "Hello from ESP32";

    logE(TAG, "Error logs");
    logD(TAG, "Debug log: Variable -> %d", a); 
    logI(TAG, "Info logs");       
    logW(TAG, "Warning logs: pi -> %f", pi);       
    logV(TAG, "Verbose logs: %s", str);
}
