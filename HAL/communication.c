#include "communication.h"

/***************************************************************************************************
* Function Name:  communication_Init
* Parameters (in): None
* Return value: None
* Description:Init the communication modules used -- Abstracting the module details from the App layer.
*
****************************************************************************************************/
void communication_Init(void){

    UART0_init();
    UART7_init();
}

/***************************************************************************************************
* Function Name:  communication_isCharAvailable
* Parameters (in): uint32_t Base
* Return value: bool
* Description:check is there a an available msgs at buffer or not
*
****************************************************************************************************/
bool communication_isCharAvailable (uint32_t Base) {
    return UARTCharsAvail(Base);
}

/***************************************************************************************************
* Function Name:  communication_getChar
* Parameters (in): uint32_t Base
* Return value: uint8_t
* Description:get the received char
*
****************************************************************************************************/
uint8_t communication_getChar (uint32_t Base)
{
    return UARTCharGet(Base);
}
/***************************************************************************************************
* Function Name:  communication_putChar
* Parameters (in):uint32_t Base,uint8_t ch
* Return value: None
* Description:send a char
*
****************************************************************************************************/
void communication_putChar(uint32_t Base,uint8_t ch)
{
    UARTCharPut(Base, ch);
}

/***************************************************************************************************
* Function Name:  communication_putString
* Parameters (in):uint8_t* str
* Return value: None
* Description:send a string
*
****************************************************************************************************/
void communication_putString(uint8_t* str)
{
    UART0_putString(str);
}
