#include "main.h"
#include "fatfs.h"
#include "sdmmc.h"
#include "gpio.h"
#include "ff.h"

#include <cstring>
#include <cstdio>

static void readContent(const char* path, int recurencyLevel = 1);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_SDMMC1_SD_Init();
    MX_FATFS_Init();
    
    if(f_mount(&SDFatFS, (const TCHAR*)SDPath, 0) != FR_OK)
        Error_Handler();

    readContent("");

    while (1)
    {
    }
}

static void readContent(const char* path, int recurencyLevel)
{
    DIR directory;
    auto result = f_opendir(&directory, (const TCHAR*)path);

    if(result != FR_OK)
    {
        if(result == FR_NO_FILESYSTEM)
        {
            char buffer[1024];
            result = f_mkfs((const TCHAR*)path, FM_EXFAT, 0, buffer, sizeof(buffer));

            if(result != FR_OK)
                Error_Handler();
        }
        else
            Error_Handler();
    }

    FILINFO fileInfo;

    while (true)
    {
        if(FRESULT result = f_readdir(&directory, &fileInfo); result != FR_OK or fileInfo.fname[0] == '\0')
            break;

        if(fileInfo.fname[0] == '.')
            continue;

        auto* fileName = fileInfo.fname;
        char tmp[30];
        auto index = 0;
        while(fileName[index] != 0)
        {
            tmp[index] = (char)(fileName[index]); 
            ++index;
        }

        if(recurencyLevel == 1)
        {
            printf("   |__");
        }
        else if(recurencyLevel == 2)
        {
            printf("   |   |__");
        }

        if((fileInfo.fattrib & AM_DIR) == AM_DIR)
        {
            strcat(tmp, "\n");
            printf("%s", tmp);
            readContent((const char*)fileName, 2);
        }
        else
        {
            strcat(tmp, "\n");
            printf("%s", tmp);
        }

        if(((fileInfo.fattrib & AM_DIR) == AM_DIR) and (recurencyLevel == 2))
            readContent((const char*)fileName, 2);
    }

    f_closedir(&directory);
}


extern "C" 
{
    void SystemClock_Config(void)
    {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 400;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** Activate the Over-Drive mode
     */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
    {
        Error_Handler();
    }
    }

    /* USER CODE BEGIN 4 */

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
}