/*******************************************************************************
  MPLAB Harmony Application Header File
  Company:
    Microchip Technology Inc.
  File Name:
    app.h
  Summary:
    This header file provides prototypes and definitions for the application.
  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.
Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).
You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.
SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _COMM_H
#define _COMM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "system_config.h"
#include "system_definitions.h"
#include "app_public.h"
#include "debug.h"
#include "jsmn.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
#define TEAM_SIX_STRING_LENGTH 6
#define JSON_MSG_MAX_SIZE 500
#define MOVEMENT_MAX_SIZE 10

// *****************************************************************************
/* Application Data
  Summary:
    Holds application data
  Description:
    This structure holds the application's data.
  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    QueueHandle_t commQ; // app's msg q - holds elapsed time intervals
    unsigned int timeMsg;  // time interval received from ISR in msec
    unsigned int elapsedTime;   // elapsed time in msec
    unsigned char *teamString;  // "Team 6"
    unsigned char displayChar;  // current char displayed to output
    unsigned int dispCharIndx;  // current index of display char array
    bool sendReceive;
    unsigned int delimitCounter;
    unsigned char sendToUARTString[JSON_MSG_MAX_SIZE];
    bool isReceiving;
} COMMUNICATION_DATA;

static char incomingJson[JSON_MSG_MAX_SIZE];
static char msgReceived[JSON_MSG_MAX_SIZE];
static int jsonIndex;
static char movement[MOVEMENT_MAX_SIZE];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/
	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )
  Summary:
     MPLAB Harmony application initialization routine.
  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.
  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").
  Parameters:
    None.
  Returns:
    None.
  Example:
    <code>
    APP_Initialize();
    </code>
  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void COMMUNICATION_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )
  Summary:
    MPLAB Harmony Demo application tasks function
  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.
  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.
  Parameters:
    None.
  Returns:
    None.
  Example:
    <code>
    APP_Tasks();
    </code>
  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void COMMUNICATION_Tasks( void );

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */
