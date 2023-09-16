#include <HAL/LEDs.h>

/***************************************************************************************************
* Function Name:  LEDs_init
* Parameters (in): None
* Return value: None
* Description:It enables the clock and set the direction of the LEDs.
*
****************************************************************************************************/
void LEDs_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {}
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
}

/***************************************************************************************************
* Function Name:  LEDs_blueOn
* Parameters (in): None
* Return value: None
* Description:turn on the blue LED
*
****************************************************************************************************/
void LEDs_blueOn(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, BLUE_LED);
}

/***************************************************************************************************
* Function Name:  LEDs_redOn
* Parameters (in): None
* Return value: None
* Description:turn on the red LED.
*
****************************************************************************************************/
void LEDs_redOn(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, RED_LED);
}

/***************************************************************************************************
* Function Name:  LEDs_whiteOn
* Parameters (in): None
* Return value: None
* Description:turn on the white LED.
*
****************************************************************************************************/
void LEDs_whiteOn(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, WHITE_LED);
}

/***************************************************************************************************
* Function Name:  LEDs_redOn
* Parameters (in): None
* Return value: None
* Description:turn off all LEDs.
*
****************************************************************************************************/
void LEDs_allOff(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
}


