/*********************************************
*
* SPICE City (tm) MAIN PROGRAM
*
* authors:
*           Sharon Fan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/

// general includes
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// SPICE-City-specific includes
#include<phidget22.h>
#include "SC_infrastructure.h"
#include "SC_railway.h"
#include "SC_lights.h"
#include "SC_powerstations.h"

int main(void)
{
	/* initialize workspace
    */
    PhidgetDigitalInputHandle EMERGENCY; // EMERGENCY STOP Button channel

	//Create your Phidget channels
	PhidgetDigitalInput_create(&EMERGENCY);

	//Set addressing parameters to specify which channel to open (if any)
	Phidget_setIsHubPortDevice((PhidgetHandle)EMERGENCY, EMERGENCY_PH);
	Phidget_setHubPort((PhidgetHandle)EMERGENCY, EMERGENCY_PH_port);

    /* install interrupt handlers...
        - event handlers
        - attach/detach handlers (checking for bad connections)
    */
    PhidgetDigitalInput_setOnStateChangeHandler(EMERGENCY, onEMERGENCY_StateChange, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)EMERGENCY, onEMERGENCY_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)EMERGENCY, onEMERGENCY_Detach, NULL);
    /* Open your Phidgets and wait for attachment

    */
	Phidget_openWaitForAttachment((PhidgetHandle)EMERGENCY, 5000);
    
    
    /* implement SPICE City Show (script follows)
    */
    while (1)
	{ /*
        SC_Delay(15); // wait for Boss G to plug everything in, get his coffee, etc.

        // make sure everything is off--- disconnect power from generators, turn off all city 
        // lights
        SC_Shutdown();
        SC_Delay(10); // delay for 10 seconds

		// cue music, turn on ambient lighting
        SC_Soundtrack_Start(); // Narrator: "Not long from now, hopefully, we'll all be living 
                               // in sustainable garden cities... welcome to SPICE City, a place
                               // showcasing a blend of renewable energy, hydrogen power, 
                               // excellent transportation, etc."
        SC_Light_Morning();
        SC_Delay(30); // delay for 30 seconds
        SC_Start(); // turn on the generators, begin transit service, get people working!
        SC_Delay(60); // let things run for 60 seconds

        SC_Light_Midday();
        SC_Turn_On_HDLoad_A();
        SC_Delay(10);
        SC_Activate_gW_1(); // solar
        SC_Turn_On_HDLoad_B();
        SC_Delay(10);
        SC_Activate_gW_2(); // wind

        SC_Light_Evening();
        SC_Deactivate_gW_1(); // solar konks out (no sun)
        SC_Delay(2);
        SC_Activate_HELIOS(); // stored hydrogen and fuel cells to the rescue!
        SC_Delay(30); 
      */
	}



    /* close your Phidgets once the program is done.
    */
	Phidget_close((PhidgetHandle)EMERGENCY);
	PhidgetDigitalInput_delete(&EMERGENCY);


	return 0;
}
