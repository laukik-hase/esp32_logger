#ifndef _LOGGER_H
#define _LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/unistd.h>
#include <sys/stat.h>

#include "esp_system.h"
#include "esp_err.h"

/*!< Default logging level*/
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"
// For more information on ESP-IDF logging:
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/log.html

#define LOG_BUFFER_SIZE (512)

/*!< Bigger chunks of debugging information, or frequent messages which can potentially flood the output. */
#define logV(TAG, fmt, ...) logger(ESP_LOG_VERBOSE, TAG, __LINE__, __func__, fmt, ##__VA_ARGS__)
/*!< Extra information which is not necessary for normal use (values, pointers, sizes, etc). */
#define logD(TAG, fmt, ...) logger(ESP_LOG_DEBUG, TAG, __LINE__, __func__, fmt, ##__VA_ARGS__)
/*!< Information messages which describe normal flow of events */
#define logI(TAG, fmt, ...) logger(ESP_LOG_INFO, TAG, __LINE__, __func__, fmt, ##__VA_ARGS__)
/*!< Error conditions from which recovery measures have been taken */
#define logW(TAG, fmt, ...) logger(ESP_LOG_WARN, TAG, __LINE__, __func__, fmt, ##__VA_ARGS__)
/*!< Critical errors, software module can not recover on its own */
#define logE(TAG, fmt, ...) logger(ESP_LOG_ERROR, TAG, __LINE__, __func__, fmt, ##__VA_ARGS__)

/**
 * @brief Print the custom log string
 * 
 * @param level ESP_LOG_LEVEL - Verbose, Debug, Info, Warning, Error
 * @param TAG Can be used to denote the component or file from where the log is originating, to simplify logs
 * @param line The line number at which the log is originating
 * @param func The function name from which the log is originating
 * @param fmt The format string - Data to be logged
 * @param ... 
 */
void logger(esp_log_level_t level, const char *TAG, int line, const char *func, const char *fmt, ...);

#endif