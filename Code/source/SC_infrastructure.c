/*********************************************
*
* SPICE City (tm) Infrastructure Source
*
*   items included:
*       core script functions 
*       EMERGENCY Stop Button
*       Ambient Light Switches/Buttons
*
* authors:
*           Sharon Fan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/
#include "SC_infrastructure.h"



/******************************************
*
* EMERGENCY button code
*
*
*******************************************/
static void CCONV onEMERGENCY_StateChange(PhidgetDigitalInputHandle ch, void * ctx, int state) 
{
	// output any status change
    printf("EMERGENCY Button State: %d\n", state);

    if (state == 1)
    {
        // disconnect High-Demand Intermittent Load, Generator A

        // disconnect High-Demand Intermittent Load, Generator B
    
        // turn off gridWISE Microgrid 1

        // turn off gridWISE Microgrid 2
    
        // turn off circuit breaker to DC Motor A

        // turn off circuit breaker to DC Motor B

        // shutdown music

        // keep lights on for safety
    }

}
//
static void CCONV onEMERGENCY_Attach(PhidgetHandle ch, void * ctx)
{
	printf("EMERGENCY Button Attached!\n");
}
//
static void CCONV onEMERGENCY_Detach(PhidgetHandle ch, void * ctx) 
{
	printf("EMERGENCY Button Detached!\n");
}
