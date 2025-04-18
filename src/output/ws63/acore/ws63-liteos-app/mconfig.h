/* Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2022-2022. All rights reserved. */
#define CONFIG_SAMPLE_ENABLE 1
#define CONFIG_ENABLE_PRODUCTS_SAMPLE 1
#define CONFIG_SAMPLE_SUPPORT_SLE_UART 1
#define CONFIG_SLE_UART_BUS 0
#define CONFIG_UART_TXD_PIN 15
#define CONFIG_UART_RXD_PIN 16
#define CONFIG_SAMPLE_SUPPORT_SLE_UART_SERVER 1
#define CONFIG_SAMPLE_SUPPORT_NORMAL_TYPE 1
#define CONFIG_SUPPORT_SLE_PERIPHERAL 1
#define CONFIG_CHIP_WS63 1
#define CONFIG_BGLE_RAM_SIZE_32K 1
#define CONFIG_RADAR_SENSOR_RX_MEM_8K 1
#define CONFIG_LWIP_COMPILE_PATH "${ROOT_DIR}/open_source/lwip/lwip_v2.1.3"
#define CONFIG_PRINTF_BUFFER_DYNAMIC 1
#define CONFIG_UART0_BAUDRATE 115200
#define CONFIG_UART1_BAUDRATE 921600
#define CONFIG_UART2_BAUDRATE 115200
#define CONFIG_DEBUG_UART 0
#define CONFIG_DEBUG_UART_BAUDRATE 115200
#define CONFIG_LOG_UART 1
#define CONFIG_LOG_UART_BAUDRATE 921600
#define CONFIG_AT_UART 0
#define CONFIG_AT_UART_BAUDRATE 115200
#define CONFIG_WVT_UART 2
#define CONFIG_WVT_UART_BAUDRATE 115200
#define CONFIG_TESTSUIT_UART 0
#define CONFIG_TESTSUIT_UART_BAUDRATE 115200
#define CONFIG_REG_WHITELIST 1
#define CONFIG_UART0_SUPPORT_WRITE_MUTEX 1
#define CONFIG_UART1_SUPPORT_WRITE_MUTEX 1
#define CONFIG_UART2_SUPPORT_WRITE_MUTEX 1
#define CONFIG_UART_SUPPORT_PORTTING_IRQ 1
#define CONFIG_PM_SUPPORT_WKUP_UART 1
#define CONFIG_DRIVER_SUPPORT_ADC 1
#define CONFIG_ADC_SUPPORT_AUTO_SCAN 1
#define CONFIG_ADC_USING_V154 1
#define CONFIG_AFE_SAMPLE_TIMES 4
#define CONFIG_DRIVER_SUPPORT_DMA 1
#define CONFIG_DMA_SUPPORT_LLI 1
#define CONFIG_DMA_SUPPORT_LPM 1
#define CONFIG_SUPPORT_DATA_CACHE 1
#define CONFIG_DRIVER_SUPPORT_EFUSE 1
#define CONFIG_EFUSE_USING_V151 1
#define CONFIG_EFUSE_REGION_NUM 1
#define CONFIG_DRIVER_SUPPORT_GPIO 1
#define CONFIG_GPIO_SUPPORT_LPM 1
#define CONFIG_GPIO_USING_V150 1
#define CONFIG_GPIO_BANK_NUM 2
#define CONFIG_GPIO0_WIDTH 32
#define CONFIG_GPIO1_WIDTH 32
#define CONFIG_DRIVER_SUPPORT_I2C 1
#define CONFIG_I2C_SUPPORT_MASTER 1
#define CONFIG_I2C_WAIT_CONDITION_TIMEOUT 0x3000
#define CONFIG_I2C_USING_V150 1
#define CONFIG_DRIVER_SUPPORT_I2S 1
#define CONFIG_I2S_BUS_MAX_NUM 1
#define CONFIG_I2S_SUPPORT_LOOPBACK 1
#define CONFIG_I2S_SCLK_PIN 13
#define CONFIG_I2S_WS_PIN 14
#define CONFIG_I2S_DO_PIN 15
#define CONFIG_I2S_DI_PIN 16
#define CONFIG_I2S_SCLK_PIN_MODE 35
#define CONFIG_I2S_WS_PIN_MODE 36
#define CONFIG_I2S_DO_PIN_MODE 37
#define CONFIG_I2S_DI_PIN_MODE 38
#define CONFIG_DRIVER_SUPPORT_PM 1
#define CONFIG_DRIVER_SUPPORT_PMP 1
#define CONFIG_PMP_USING_RISCV_31 1
#define CONFIG_DRIVER_SUPPORT_PWM 1
#define CONFIG_PWM_USING_V151 1
#define CONFIG_PWM_GROUP_NUM 8
#define CONFIG_PWM_CHANNEL_NUM 6
#define CONFIG_DRIVER_SUPPORT_SECURITY_UNIFIED 1
#define CONFIG_SECURITY_UNIFIED_SUPPORT_SYMC 1
#define CONFIG_SECURITY_UNIFIED_SUPPORT_HASH 1
#define CONFIG_SECURITY_UNIFIED_SUPPORT_TRNG 1
#define CONFIG_SECURITY_UNIFIED_SUPPORT_KM 1
#define CONFIG_SECURITY_UNIFIED_SUPPORT_PKE 1
#define CONFIG_PKE_SUPPORT_ECC_FIPS_P192R 1
#define CONFIG_PKE_SUPPORT_ECC_FIPS_P224R 1
#define CONFIG_PKE_SUPPORT_ECC_FIPS_P256R 1
#define CONFIG_PKE_SUPPORT_ECC_BP256R 1
#define CONFIG_PKE_SUPPORT_RSA 1
#define CONFIG_PKE_SUPPORT_ECC_SIGN 1
#define CONFIG_PKE_SUPPORT_ECC_VERIFY 1
#define CONFIG_PKE_SUPPORT_ECC_ECDH 1
#define CONFIG_PKE_SUPPORT_ECC_GEN_KEY 1
#define CONFIG_ENTROPY_SOURCES_FROM_FRO 1
#define CONFIG_SM_EFUSE_CHECK 1
#define CONFIG_DRIVER_SUPPORT_SFC 1
#define CONFIG_DRIVER_SUPPORT_SPI 1
#define CONFIG_SPI_MAX_TIMEOUT 0xFFFFFFFF
#define CONFIG_SPI_TXFTLR 0x1
#define CONFIG_SPI_RXFTLR 0x1
#define CONFIG_SPI_NOT_SUPPORT_TEXAS_FORMAT 1
#define CONFIG_SPI_USING_V151 1
#define CONFIG_DRIVER_SUPPORT_TSENSOR 1
#define CONFIG_TSENSOR_USING_V151 1
#define CONFIG_TSENSOR_TEMP_COMPENSATION 1
#define CONFIG_TSENSOR_DELAY_TIME 1
#define CONFIG_TSENSOR_WAIT_TIME_MS 5
#define CONFIG_DRIVER_SUPPORT_UART 1
#define CONFIG_UART_SUPPORT_TX_INT 1
#define CONFIG_UART_FIFO_DEPTH 64
#define CONFIG_UART_DLF_SIZE 6
#define CONFIG_UART_USING_V151 1
#define CONFIG_DRIVER_SUPPORT_WDT 1
#define CONFIG_WATCHDOG_ALREADY_START 1
#define CONFIG_WATCHDOG_USING_V151 1
#define CONFIG_WATCHDOG_USING_V151_RST_PL 7
#define CONFIG_DRIVER_SUPPORT_LITEOS 1
#define CONFIG_DRIVER_SUPPORT_LITEOS_208_5_0 1
#define CONFIG_DRIVER_DISABLE_OSAL_LOG 1
#define CONFIG_MIDDLEWARE_CHIP_WS63 1
#define CONFIG_MIDDLEWARE_SUPPORT_FTM 1
#define CONFIG_MIDDLEWARE_SUPPORT_NV 1
#define CONFIG_MIDDLEWARE_NV_SUPPORT_HSO_ACCESS 1
#define CONFIG_PARTITION_FEATURE_SUPPORT 1
#define CONFIG_MIDDLEWARE_SUPPORT_UPG 1
#define CONFIG_MIDDLEWARE_SUPPORT_UPG_AB 1
#define CONFIG_MIDDLEWARE_SUPPORT_EXCEPT_REBOOT 1
#define CONFIG_SUPPORT_CRASHINFO_SAVE_TO_FLASH 1
#define CONFIG_MIDDLEWARE_SUPPORT_PM 1
#define CONFIG_MIDDLEWARE_SUPPORT_DFX 1
#define CONFIG_DFX_SUPPORT_USERS_PRINT 1
#define CONFIG_DFX_SUPPORT_PRINT 1
#define CONFIG_MIDDLEWARE_SUPPORT_AT 1
#define CONFIG_AT_SUPPORT_PLT 1
#define CONFIG_AT_SUPPORT_ZDIAG 1
#define CONFIG_AT_BLE 1
#define CONFIG_AT_GLE 1
#define CONFIG_TEST_SUPPORT_TESTSUITE 1
#define CONFIG_TEST_SUITE_FUNCTIONS_MAX_FUNCS 200
#define CONFIG_TEST_CONSOLE_HISTORY_LEN 10
#define CONFIG_TEST_SUITE_TASK_STACK_SIZE 0x1000
