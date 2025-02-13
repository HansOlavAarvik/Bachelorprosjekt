#include "div.h"
#include "main.h"  // For UART handle
#include <string.h>

extern UART_HandleTypeDef huart3;  // Add this to reference huart3 from main.c

void dprint(const char* str)
{
    size_t len = strlen(str);
    uint8_t buffer[len + 2];
    
    strcpy((char*)buffer, str);
    buffer[len] = '\n';
    buffer[len + 1] = '\0';
    
    HAL_UART_Transmit(&huart3, buffer, len + 1, 1000);
}