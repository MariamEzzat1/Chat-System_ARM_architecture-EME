
#ifndef HAL_BUTTONS_H_
#define HAL_BUTTONS_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))
/*******************************************************************************
 *                               Type Definitions                              *
 *******************************************************************************/
typedef enum{NA,SW0,SW4} pressed_button;

/*******************************************************************************
 *                               externs                                       *
 *******************************************************************************/
extern pressed_button button;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void buttons_init();
void portF_IntHandler(void);

#endif /* HAL_BUTTONS_H_ */
