#include <App/chat_app.h>


User_state state=ONLINE;
uint8_t* error_msg="\rMessage limit exceeded. The message has been ignored.\n";

/***************************************************************************************************
* Function Name:  chat_init
* Parameters (in): None
* Return value: None
* Description:inits the system's modules.
*
****************************************************************************************************/
void chat_init(void)
{
    buttons_init();
    LEDs_init();
    communication_Init();
}

/***************************************************************************************************
* Function Name:  chat_app
* Parameters (in): None
* Return value: None
* Description:checks and handles the different chat states.
*
****************************************************************************************************/
void chat_app(void)
{
    switch (state)
    {
    case OFFLINE:
        LEDs_allOff();
        LEDs_redOn();
        if (button==SW0)
        {
            state=READ_ONLY;
        }
        else if (button==SW4)
        {
            state=ONLINE;
        }
        else
        {}
        button = NA;
        CLEAR_recievedFlag();
        CLEAR_sendFlag();
        break;

    case READ_ONLY:
        LEDs_allOff();
        LEDs_blueOn();
        recieve();
        if (button==SW0)
        {
            state=ONLINE;
        }
        else if (button==SW4)
         {
           state=OFFLINE;
         }
        else
        {

        }
        button = NA;
        break;
    case ONLINE:

        LEDs_allOff();
        LEDs_whiteOn();
        send();
        recieve();


        if (button==SW0)
        {
            state=OFFLINE;
        }
        else if (button==SW4)
         {
           state=READ_ONLY;
         }
        else
        {

        }
        button = NA;

        break;
    default:
        button = NA;
        CLEAR_recievedFlag();
        CLEAR_sendFlag();
        break;
    }
}


/***************************************************************************************************
* Function Name:  send
* Parameters (in): None
* Return value: None
* Description:checks and handles the entered data then sends it.
*
****************************************************************************************************/
void send(void)
{
    if(send_flag)
      {
        uint8_t i=0;
        uartIndex=0;
        uint8_t temp_char,error_flag=0;

        while (communication_isCharAvailable(UART0_BASE))
        {
            do
            {
                temp_char=communication_getChar(UART0_BASE);
                if(temp_char==BACKSPACE){
                    uartIndex--;
                }
                else
                {
                U0_receivedData[uartIndex] = temp_char;

                uartIndex++;

                if(uartIndex==UART_BUFFER_SIZE)
                {
                    error_flag=1;
                    UART0_putString(error_msg);
                    communication_putChar(UART0_BASE, '\r');
                    uartIndex = 0;
                    break;
                }
                }
            }
            while(temp_char!=ENTER);
        }
        if(!error_flag){



        for(i =0;i<uartIndex;i++)
        {
            communication_putChar(UART7_BASE, U0_receivedData[i] );
        }
        communication_putChar(UART0_BASE, NEW_LINE);

        }
        else
        {
            uartIndex=0;
            error_flag=0;
        }
        send_flag=0;
    }
}
/***************************************************************************************************
* Function Name:  recieve
* Parameters (in): None
* Return value: None
* Description:completes the reception operation and process the received data.
*
****************************************************************************************************/
void recieve(void)
{
    if(recieve_flag){
        uart7_Index=0;

        uint8_t temp_char;

        while (communication_isCharAvailable(UART7_BASE))
        {

            do
            {
                temp_char=communication_getChar(UART7_BASE);

                U7_receivedData[uart7_Index] = temp_char;

                communication_putChar(UART0_BASE,U7_receivedData[uart7_Index] );
                uart7_Index++;
            }
            while(temp_char!=ENTER);
            communication_putChar(UART0_BASE,NEW_LINE );
        }
    }
    recieve_flag=0;
 }
