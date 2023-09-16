
#include "UART.h"


/**************************************************************************************************
 *                                Global variables                                                *

***************************************************************************************************/
volatile uint8_t U0_receivedData[UART_BUFFER_SIZE];
volatile uint8_t U7_receivedData[UART_BUFFER_SIZE];
volatile uint32_t uartIndex = 0;
volatile uint32_t uart7_Index = 0;
volatile uint8_t send_flag=0;
volatile uint8_t recieve_flag=0;


/***************************************************************************************************
* Function Name:  UART0_init
* Parameters (in): None
* Return value: None
* Description:initialize UART-0 Module in 8-bits ,baud rate of 9600
* it also enables the interrupt of Rx.
*
****************************************************************************************************/
void UART0_init(void)
{

       SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);    /* Enable UART0 module*/
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);    /* Enable GPIO-port A module*/


       GPIOPinConfigure(GPIO_PA0_U0RX);
       GPIOPinConfigure(GPIO_PA1_U0TX);
       GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);   /* Configure UART0 pins*/


       UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600,
                           (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)); /* Configure UART0 with a baud rate of 9600*/
       UARTFIFOLevelSet(UART0_BASE, UART_FIFO_TX1_8, UART_FIFO_RX1_8);  /*trigger interrupt after each reception*/


       UARTIntRegister(UART0_BASE, UART0_sendSignal); /*set the callback function - ISR Handler*/
       UARTIntEnable(UART0_BASE, UART_INT_RX); /* Enable UART0 Rx interrupt*/


       IntPrioritySet(INT_UART0,1);  /* Set interrupt priority 1 in NVIC*/

       IntEnable(INT_UART0);    /* Enable UART0 interrupt in the NVIC*/

       IntMasterEnable();/* Enable global interrupts*/
}


/***************************************************************************************************
* Function Name:  UART0_sendSignal
* Parameters (in): None
* Return value: None
* Description:raises send_flag whenever the message is to be sent.
*
****************************************************************************************************/
void UART0_sendSignal(void)
{
    send_flag=1;
    uint32_t status = UARTIntStatus(UART0_BASE, true);
    UARTIntClear(UART0_BASE, status);

}

/***************************************************************************************************
* Function Name:  UART0_putString
* Parameters (in): uint8_t *str
* Return value: None
* Description:sends a string through uart-0 .
*
****************************************************************************************************/
void UART0_putString(uint8_t *str)
{
    uint8_t i=0;
    while(UARTBusy(UART0_BASE)){}
    UARTCharPut(UART0_BASE, '\r');
    while(str[i]!='\0')
    {
        UARTCharPut(UART0_BASE, str[i]);
        i++;
    }
 }

#ifdef UART7

/***************************************************************************************************
* Function Name:  UART7_init
* Parameters (in): None
* Return value: None
* Description:initialize UART-7 Module in 8-bits ,baud rate of 9600
* it also enables the interrupt of Rx.
*
****************************************************************************************************/
void UART7_init(void)
{

       SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7); /* Enable UART7 module*/
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); /* Enable GPIO-port E module*/


       GPIOPinConfigure(GPIO_PE0_U7RX);
       GPIOPinConfigure(GPIO_PE1_U7TX);
       GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);/* Configure UART7 pins*/


       UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 9600,
                          (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
       UARTFIFOLevelSet(UART7_BASE, UART_FIFO_TX1_8, UART_FIFO_RX1_8);/* Configure UART0 with a baud rate of 9600*/

       UARTIntRegister(UART7_BASE, UART7_recieveSignal); /*set the callback function - ISR Handler*/
       UARTIntEnable(UART7_BASE, UART_INT_RX); /* Enable UART0 Rx interrupt*/

       IntPrioritySet(INT_UART7,0);  /* Set interrupt priority to 0 (highest)*/


       IntEnable(INT_UART7);  /* Enable UART7 interrupt in the NVIC*/
       IntMasterEnable();   /* Enable global interrupts*/
}
/***************************************************************************************************
* Function Name:  UART7_recieveSignal
* Parameters (in): None
* Return value: None
* Description:raises a flag to complete the reception's operation .
*
****************************************************************************************************/
void UART7_recieveSignal(void)
{
    recieve_flag=1;
    uint32_t status = UARTIntStatus(UART7_BASE, true);
    UARTIntClear(UART7_BASE, status);

}



/***************************************************************************************************
* Function Name:  CLEAR_recievedFlag
* Parameters (in): None
* Return value: None
* Description:reset the flag of the reception.
*
****************************************************************************************************/
void CLEAR_recievedFlag(void){
    recieve_flag=0;

}

/***************************************************************************************************
* Function Name:  CLEAR_sendFlag
* Parameters (in): None
* Return value: None
* Description:reset the flag of the transmission.
*
****************************************************************************************************/
void CLEAR_sendFlag(void){
    send_flag=0;

}

#endif

