#ifndef HAL_LEDS_H_
#define HAL_LEDS_H_
/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BLUE_LED                 0x04
#define RED_LED                  0x02
#define WHITE_LED                0x0E

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void LEDs_init(void);
void LEDs_blueOn(void);
void LEDs_redOn(void);
void LEDs_whiteOn(void);
void LEDs_allOff(void);


#endif /* HAL_LEDS_H_ */
