
#ifndef UART_H_
#define UART_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define UART_BUFFER_SIZE    200
#define UART7

/*******************************************************************************
 *                               externs                                       *
 *******************************************************************************/
extern volatile uint8_t U0_receivedData[UART_BUFFER_SIZE];
extern volatile uint32_t uartIndex;
extern volatile uint8_t send_flag;
extern volatile uint8_t recieve_flag;
extern volatile uint32_t uart7_Index ;
extern volatile uint8_t U7_receivedData[UART_BUFFER_SIZE];

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void UART0_init(void);
void UART0_sendSignal(void);
void UART0_putString(uint8_t *str);
void UART7_init(void);
void UART7_recieveSignal(void);
void CLEAR_recievedFlag(void);
void CLEAR_sendFlag(void);




#endif /* UART_H_ */
