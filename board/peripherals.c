/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v4.1
processor: MKL27Z64xxx4
package_id: MKL27Z64VDA4
mcu_data: ksdk2_0
processor_version: 4.0.1
functionalGroups:
- name: BOARD_InitPeripherals
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * UART2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'UART2'
- type: 'uart'
- mode: 'polling'
- type_id: 'uart_cd31a12aa8c79051fda42cc851a27c37'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'UART2'
- config_sets:
  - uartConfig_t:
    - uartConfig:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'GetFreq'
      - baudRate_Bps: '115200'
      - parityMode: 'kUART_ParityDisabled'
      - idleType: 'kUART_IdleTypeStartBit'
      - enableTx: 'true'
      - enableRx: 'true'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const uart_config_t UART2_config = {
  .baudRate_Bps = 115200,
  .parityMode = kUART_ParityDisabled,
  .idleType = kUART_IdleTypeStartBit,
  .enableTx = true,
  .enableRx = true
};

void UART2_init(void) {
  UART_Init(UART2_PERIPHERAL, &UART2_config, UART2_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPUART0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART0'
- type: 'lpuart'
- mode: 'interrupts'
- type_id: 'lpuart_bebe3e12b6ec22bbd14199038f2bf459'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART0'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'BOARD_BootClockRUN'
      - baudRate_Bps: '117728'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
  - interruptsCfg:
    - interrupts: 'kLPUART_RxDataRegFullInterruptEnable'
    - interrupt_vectors:
      - enable_rx_tx_irq: 'true'
      - interrupt_rx_tx:
        - IRQn: 'LPUART0_IRQn'
        - enable_priority: 'true'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART0_config = {
  .baudRate_Bps = 117728,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};

void LPUART0_init(void) {
  LPUART_Init(LPUART0_PERIPHERAL, &LPUART0_config, LPUART0_CLOCK_SOURCE);
  LPUART_EnableInterrupts(LPUART0_PERIPHERAL, kLPUART_RxDataRegFullInterruptEnable);
  /* Interrupt vector LPUART0_IRQn priority settings in the NVIC */
  NVIC_SetPriority(LPUART0_SERIAL_RX_TX_IRQN, LPUART0_SERIAL_RX_TX_IRQ_PRIORITY);
  /* Enable interrupt LPUART0_IRQn request in the NVIC */
  EnableIRQ(LPUART0_SERIAL_RX_TX_IRQN);
}

/***********************************************************************************************************************
 * I2C0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'I2C0'
- type: 'i2c'
- mode: 'I2C_Polling'
- type_id: 'i2c_2566d7363e7e9aaedabb432110e372d7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'I2C0'
- config_sets:
  - fsl_i2c:
    - i2c_mode: 'kI2C_Master'
    - clockSource: 'BusInterfaceClock'
    - clockSourceFreq: 'GetFreq'
    - i2c_master_config:
      - enableMaster: 'true'
      - enableStopHold: 'true'
      - baudRate_Bps: '50000'
      - glitchFilterWidth: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const i2c_master_config_t I2C0_config = {
  .enableMaster = true,
  .enableStopHold = true,
  .baudRate_Bps = 50000,
  .glitchFilterWidth = 0
};

void I2C0_init(void) {
  /* Initialization function */
  I2C_MasterInit(I2C0_PERIPHERAL, &I2C0_config, I2C0_CLK_FREQ);
}

/***********************************************************************************************************************
 * GPIOC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPIOC'
- type: 'gpio'
- mode: 'GPIO'
- type_id: 'gpio_f970a92e447fa4793838db25a2947ed7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIOC'
- config_sets:
  - fsl_gpio:
    - enable_irq: 'true'
    - port_interrupt:
      - IRQn: 'PORTB_PORTC_PORTD_PORTE_IRQn'
      - enable_priority: 'false'
      - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

void GPIOC_init(void) {
  /* Make sure, the clock gate for port C is enabled (e. g. in pin_mux.c) */
  /* Enable interrupt PORTB_PORTC_PORTD_PORTE_IRQn request in the NVIC */
  EnableIRQ(PORTB_PORTC_PORTD_PORTE_IRQn);
}

/***********************************************************************************************************************
 * TPM0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'TPM0'
- type: 'tpm'
- mode: 'EdgeAligned'
- type_id: 'tpm_e7472ea12d53461b8d293488f3ed72ec'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'TPM0'
- config_sets:
  - tpm_main_config:
    - tpm_config:
      - clockSource: 'kTPM_SystemClock'
      - tpmSrcClkFreq: 'BOARD_BootClockRUN'
      - prescale: 'kTPM_Prescale_Divide_1'
      - timerFrequency: '2600'
      - useGlobalTimeBase: 'false'
      - triggerSelect: 'kTPM_Trigger_Select_0'
      - triggerSource: 'kTPM_TriggerSource_Internal'
      - enableDoze: 'false'
      - enableDebugMode: 'false'
      - enableReloadOnTrigger: 'false'
      - enableStopOnOverflow: 'false'
      - enableStartOnTrigger: 'false'
      - enablePauseOnTrigger: 'false'
    - timer_interrupts: ''
    - enable_irq: 'false'
    - tpm_interrupt:
      - IRQn: 'TPM0_IRQn'
      - enable_priority: 'false'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'false'
  - tpm_edge_aligned_mode:
    - tpm_edge_aligned_channels_config:
      - 0:
        - edge_aligned_mode: 'kTPM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kTPM_Chnl_4'
          - level: 'kTPM_HighTrue'
          - dutyCyclePercent: '50'
          - enable_chan_irq: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const tpm_config_t TPM0_config = {
  .prescale = kTPM_Prescale_Divide_1,
  .useGlobalTimeBase = false,
  .triggerSelect = kTPM_Trigger_Select_0,
  .triggerSource = kTPM_TriggerSource_Internal,
  .enableDoze = false,
  .enableDebugMode = false,
  .enableReloadOnTrigger = false,
  .enableStopOnOverflow = false,
  .enableStartOnTrigger = false,
  .enablePauseOnTrigger = false
};

const tpm_chnl_pwm_signal_param_t TPM0_pwmSignalParams[] = { 
  {
    .chnlNumber = kTPM_Chnl_4,
    .level = kTPM_HighTrue,
    .dutyCyclePercent = 50
  }
};

void TPM0_init(void) {
  TPM_Init(TPM0_PERIPHERAL, &TPM0_config);
  TPM_SetupPwm(TPM0_PERIPHERAL, TPM0_pwmSignalParams, sizeof(TPM0_pwmSignalParams) / sizeof(tpm_chnl_pwm_signal_param_t), kTPM_EdgeAlignedPwm, 2600U, TPM0_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPTMR0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPTMR0'
- type: 'lptmr'
- mode: 'LPTMR_GENERAL'
- type_id: 'lptmr_2eeab91a1a42f8238f9ac768f18c65ae'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPTMR0'
- config_sets:
  - fsl_lptmr:
    - enableInterrupt: 'true'
    - interrupt:
      - IRQn: 'LPTMR0_IRQn'
      - enable_priority: 'false'
      - enable_custom_name: 'false'
    - lptmr_config:
      - timerMode: 'kLPTMR_TimerModeTimeCounter'
      - pinSelect: 'ALT.3'
      - pinPolarity: 'kLPTMR_PinPolarityActiveHigh'
      - enableFreeRunning: 'false'
      - bypassPrescaler: 'true'
      - prescalerClockSource: 'kLPTMR_PrescalerClock_1'
      - clockSource: 'BOARD_BootClockRUN'
      - value: 'kLPTMR_Prescale_Glitch_0'
      - timerPeriod: '5s'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lptmr_config_t LPTMR0_config = {
  .timerMode = kLPTMR_TimerModeTimeCounter,
  .pinSelect = kLPTMR_PinSelectInput_3,
  .pinPolarity = kLPTMR_PinPolarityActiveHigh,
  .enableFreeRunning = false,
  .bypassPrescaler = true,
  .prescalerClockSource = kLPTMR_PrescalerClock_1,
  .value = kLPTMR_Prescale_Glitch_0
};

void LPTMR0_init(void) {
  /* Initialize the LPTMR */
  LPTMR_Init(LPTMR0_PERIPHERAL, &LPTMR0_config);
  /* Configure timer interrupt */
  LPTMR_EnableInterrupts(LPTMR0_PERIPHERAL, kLPTMR_TimerInterruptEnable);
  /* Enable interrupt LPTMR0_IRQn request in the NVIC */
  EnableIRQ(LPTMR0_IRQn);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  UART2_init();
  LPUART0_init();
  I2C0_init();
  GPIOC_init();
  TPM0_init();
  LPTMR0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
