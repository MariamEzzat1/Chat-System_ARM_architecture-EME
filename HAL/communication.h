
#ifndef HAL_COMMUNICATION_H_
#define HAL_COMMUNICATION_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include "UART.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void communication_Init(void);
bool communication_isCharAvailable (uint32_t Base);
uint8_t communication_getChar (uint32_t Base) ;
void communication_putChar(uint32_t Base,uint8_t ch);
void communication_putString(uint8_t* str);

#endif /* HAL_COMMUNICATION_H_ */
