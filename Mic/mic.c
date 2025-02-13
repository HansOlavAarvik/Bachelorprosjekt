#include "mic.h"


/* Private variables */
static uint8_t initialized = 0;


void MIC_init(void)
{
    // Add initialization code here
    initialized = 1;
}
/*
// dma test
  if(HAL_I2S_Receive_DMA(&hi2s2, (uint16_t *)data_i2s, sizeof(data_i2s)/2) != HAL_OK)
  {
      char debug[] = "DMA Start Failed!\r\n";
      HAL_UART_Transmit(&huart3, (uint8_t*)debug, strlen(debug), 100);
  }
  // I2s Recieve start
  void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s)
  {
      sample_i2s = data_i2s[0];
      // Add debug message
      char debug[32];
      sprintf(debug, "DMA IRQ: %d\r\n", sample_i2s);
      HAL_UART_Transmit(&huart3, (uint8_t*)debug, strlen(debug), 100);
  }

    // while(1)
        char str[64];  // Declare buffer before using sprintf
    sprintf(str, "Raw data: %d, %d, %d, %d\r\n", 
            data_i2s[0], data_i2s[1], data_i2s[2], data_i2s[3]);
    HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), 1000);
    
    // Also print the volatile sample
    sprintf(str, "Sample: %d\r\n", sample_i2s);
    HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), 1000);
    
    HAL_Delay(1000);

    Configure Analogue filter
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
   USER CODE BEGIN 4 
    
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s)
{
    sample_i2s = data_i2s[0];
    char str[64];
    sprintf(str, "DMA CB! Value: %d\r\n", sample_i2s);
    HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), 100);
}
    
 USER CODE END 4 */
