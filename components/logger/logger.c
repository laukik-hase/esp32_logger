#include "logger.h"

void logger(esp_log_level_t level, const char *TAG, int line, const char *func, const char *fmt, ...)
{
    char *log_print_buffer = calloc(LOG_BUFFER_SIZE, sizeof(char));
    sprintf(log_print_buffer, "%s (%s:%d) ", TAG, func, line);
    size_t fixed_length = strlen(log_print_buffer);

    va_list args;
    va_start(args, fmt);

    size_t variable_length = vsnprintf(NULL, 0, fmt, args) + 1;
    if (fixed_length + variable_length >= LOG_BUFFER_SIZE)
    {
        log_print_buffer = realloc(log_print_buffer, fixed_length + variable_length);
    }
    vsprintf(&log_print_buffer[fixed_length], fmt, args);

    va_end(args);

    switch (level)
    {
    case ESP_LOG_ERROR:
        ESP_LOGE("", "%s", log_print_buffer);
        break;
    case ESP_LOG_WARN:
        ESP_LOGW("", "%s", log_print_buffer);
        break;
    case ESP_LOG_INFO:
        ESP_LOGI("", "%s", log_print_buffer);
        break;
    case ESP_LOG_DEBUG:
        ESP_LOGD("", "%s", log_print_buffer);
        break;
    case ESP_LOG_VERBOSE:
        ESP_LOGV("", "%s", log_print_buffer);
        break;
    default:
        break;
    }

    free(log_print_buffer);
}