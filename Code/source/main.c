/*********************************************
*
* SPICE City (tm) MAIN PROGRAM
*
* authors:
*           Sharon Fan
*           Sid Swaminathan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/

// general includes
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
4
// SPICE-City-specific includes
#include<phidget22.h>

// delete soon, no longer needed: #include "SC_infrastructure.h"
#include "SC_railway.h"
#include "SC_lights.h"
#include "SC_powerstations.h"
// until Sid commits his code #include "SC_ambient.h"
#include "SC_gridWISE.h"

// TIMING MACROS

#define     TRAINSTOP           10 // <--- should be in railway.c
#define     MORNING             200


int main(void)
{
	/* initialize workspace
    */
    //CreateSCLights(); // initialize controllable LEDs throughout SPICE City
    //CreateRailways();
    //CreateInfrastructure(); // initialize EMERGENCY button, ambient lights, etc.
 
    /* implement SPICE City Show (script follows)
    */
     while (1)
	{ 
        /*
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
        SC_Delay(MORNING); // delay for 30 seconds
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
         
         SC_Light_Night();
         
      */
	}
    // additional comment
    //ShutdownSCLights();
    //ShutdownRailways();
    //ShutdownInfrastructure();
 
	return 0;
}
