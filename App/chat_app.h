

#ifndef APP_CHAT_APP_H_
#define APP_CHAT_APP_H_


/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <HAL/Buttons.h>
#include <HAL/LEDs.h>
#include <HAL/communication.h>
//#include <stdio.h>
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ENTER        '\x0d'
#define NEW_LINE     '\n'
#define BACKSPACE    (uint8_t)8
/*******************************************************************************
 *                               Type Definitions                              *
 *******************************************************************************/
typedef enum{OFFLINE,READ_ONLY,ONLINE} User_state;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void chat_init(void);
void chat_app(void);
void send(void);
void recieve(void);



#endif /* APP_CHAT_APP_H_ */
