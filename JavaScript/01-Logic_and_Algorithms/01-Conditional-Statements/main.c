/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SIGMA 10.0f
#define BETA (8.0f / 3.0f)
#define RHO 120.0f
//50 | 70 | 120
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

void lorenz(float x, float y, float z, float *dx, float *dy, float *dz);

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

char buf[100];
uint8_t buf_len = 0;

// Condições iniciais
float h = 0.01;     // Passo de tempo
float x_0 = 1.0f, y_0 = 1.0f, z_0 = 0.0f;
//0 1 1 | 1 0 1 | 1 1 0
uint32_t n = 50000;       // Numero de passos|iteracoes
//5000 | 10000 | 50000

// Tempo
uint32_t tick1 = 0, tick2 = 0, counter1 = 0, counter2 = 0;
uint8_t counter0_tick1 = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LPUART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  //HAL_Delay(200); // Garante não imprimir UART em tempo de rodar o codigo novamente

  HAL_TIM_Base_Start(&htim2);

  tick1 = HAL_GetTick(); // 1ms
  //counter1 = __HAL_TIM_GET_COUNTER(&htim2); //  2 ms

  float x = x_0;
  float y = y_0;
  float z = z_0;

  // Simulação usando o método de Runge-Kutta de 4ª ordem
  for (uint32_t i = 0; i < n; i++) {
	  float k1x, k1y, k1z;
	  float k2x, k2y, k2z;
	  float k3x, k3y, k3z;
	  float k4x, k4y, k4z;

	  lorenz(x, y, z, &k1x, &k1y, &k1z);
	  lorenz(x + h * k1x / 2.0f, y + h * k1y / 2.0f, z + h * k1z / 2.0f, &k2x, &k2y, &k2z);
	  lorenz(x + h * k2x / 2.0f, y + h * k2y / 2.0f, z + h * k2z / 2.0f, &k3x, &k3y, &k3z);
	  lorenz(x + h * k3x, y + h * k3y, z + h * k3z, &k4x, &k4y, &k4z);

	  x += h * (k1x + 2.0f * k2x + 2.0f * k3x + k4x) / 6.0f;
	  y += h * (k1y + 2.0f * k2y + 2.0f * k3y + k4y) / 6.0f;
	  z += h * (k1z + 2.0f * k2z + 2.0f * k3z + k4z) / 6.0f;
  }

  tick2 = HAL_GetTick(); // 1ms
  //counter2 = __HAL_TIM_GET_COUNTER(&htim2); //  2 ms

  if(counter2 == 0)counter0_tick1=1;

  // Imprimir o estado atual com precisao maxima para float
  buf_len = sprintf(buf, "q%.1fr%.1fs%.1ft%.1fu%luv%.1fw%.4fx%.4fy%.4fz", x_0, y_0, z_0, RHO, n, ((float)((counter2 != 0)*(counter2-counter1)/10) + (counter2 == 0)*(tick2-tick1)), x, y, z);
  buf_len = sprintf(buf, "x%uy1%u", buf_len, counter0_tick1);
  HAL_UART_Transmit(&hlpuart1, (uint8_t *)buf, buf_len, HAL_MAX_DELAY);
  buf_len = sprintf(buf, "q%.1fr%.1fs%.1ft%.1fu%luv%.1fw%.4fx%.4fy%.4fz", x_0, y_0, z_0, RHO, n, ((float)((counter2 != 0)*(counter2-counter1)/10) + (counter2 == 0)*(tick2-tick1)), x, y, z);
  HAL_UART_Transmit(&hlpuart1, (uint8_t *)buf, buf_len, HAL_MAX_DELAY);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void lorenz(float x, float y, float z, float *dx, float *dy, float *dz) {
    *dx = SIGMA * (y - x);
    *dy = x * (RHO - z) - y;
    *dz = x * y - BETA * z;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
