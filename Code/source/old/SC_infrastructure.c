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
#include<stdio.h>
#include<phidget22.h>

#define     EMERGENCY_Button_Sensor_PH              767874
#define     EMERGENCY_Button_Sensor_port            3
#define     EMERGENCY_Circuit_Breaker_PH            767874
#define     EMERGENCY_Circuit_Breaker_PH_CB_chan    10    



/***************************************

    local variables

****************************************/

    PhidgetDigitalInputHandle EMERGENCY; // EMERGENCY STOP Button channel




/***************************************

    local functions


****************************************/

static CCONV void onEMERGENCY_StateChange (void)
{

}

static CCONV void onEMERGENCY_Attach (void)
{

}


/******************************************

 EMERGENCY button interface functions


*******************************************/

void CreateInfrastructure (void)
{
	//Create your Phidget channels
	PhidgetDigitalInput_create(&EMERGENCY);

	//Set addressing parameters to specify which channel to open (if any)
	Phidget_setIsHubPortDevice((PhidgetHandle)EMERGENCY, EMERGENCY_PH);
	Phidget_setHubPort((PhidgetHandle)EMERGENCY, EMERGENCY_PH_port);
   */
    /* install interrupt handlers...
        - event handlers
        - attach/detach handlers (checking for bad connections)
    */
    PhidgetDigitalInput_setOnStateChangeHandler(EMERGENCY, onEMERGENCY_StateChange, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)EMERGENCY, onEMERGENCY_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)EMERGENCY, onEMERGENCY_Detach, NULL);
    /
    
    * Open your Phidgets and wait for attachment

    */ 


	/*Phidget_openWaitForAttachment((PhidgetHandle)EMERGENCY, 5000);
    */
}

void ShutdownInfrasctructure (void)
{
    /* close your Phidgets once the program is done.
    */
	Phidget_close((PhidgetHandle) EMERGENCY);
	PhidgetDigitalInput_delete(&EMERGENCY);
    return;
}




void CCONV onEMERGENCY_StateChange(PhidgetDigitalInputHandle ch, void * ctx, int state) 
{
	// output any status change
    printf("EMERGENCY Button State: %d\n", state);

   /* if (state == 1)
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
    */
    return;

}
//
void CCONV onEMERGENCY_Attach(PhidgetHandle ch, void * ctx)
{
	printf("EMERGENCY Button Attached!\n");
    return;
}
//
void CCONV onEMERGENCY_Detach(PhidgetHandle ch, void * ctx) 
{
	printf("EMERGENCY Button Detached!\n");
    return;
}
