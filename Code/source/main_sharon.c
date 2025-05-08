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
#include<pthread.h>
#include <unistd.h>  // For sleep()
#include <time.h>    // For time tracking

// SPICE-City-specific includes
#include<phidget22.h>
#include "SC_infrastructure.h"
#include "SC_railway.h"
#include "SC_lights.h"
#include "SC_powerstations.h"

#define RUN_TIME        900  // 15 minutes in seconds
#define BREAK_TIME      300  // 5 minutes in seconds

volatile int KeepRunning = 1; //flag to control infinite looping

/*
// Keyboard Intteruption
void* monitor_keyboard(void* arg) {
    printf("Press Enter to stop the railway system and power station system...\n");
    getchar(); // Wait for user to press Enter
    KeepRunning = 0; // Signal to stop the loop
    return NULL;
}
*/

int main(void)
{
	/* initialize workspace
    */
    railway_init();
    railway_start();

    PowerStation_A_init();
    PowerStation_B_init();
    PowerStation_A_start();
    PowerStation_B_start();

    PowerStation_A_PowerOn();
    PowerStation_B_PowerOn();
    
    /*
    // Create a seperate thread to listen for keyboard input for interruption
    pthread_t keyboardThread;
    pthread_create(&keyboardThread, NULL, monitor_keyboard,NULL);
    */

    /* implement SPICE City Show (script follows)
    */
    while (KeepRunning) {  // Infinite loop to repeat the cycle
        printf("Starting 15-minute train and power station control cycle...\n");

        time_t start_time = time(NULL);

        while (time(NULL) - start_time < RUN_TIME) {
            // The distance sensors in railway.c will control train stops
            printf("Running... Time elapsed: %ld seconds\n", time(NULL) - start_time);  // Log time elapsed
            sleep(5);  // Small delay before checking again
        }

        // Every 15 minutes, power off the entire system
        printf("15 minutes elapsed. Powering off the entire system...\n");
        railway_system_power_off();
        PowerStation_A_PowerOff();
        PowerStation_B_PowerOff();

        sleep(BREAK_TIME);  // Take a 5-minute break
        printf("5-minute break over. Powering the system back on...\n");
        railway_system_power_on();  // Resume operations
        PowerStation_A_PowerOn();
        PowerStation_B_PowerOn();

        printf("Resuming railway and Power Station operations...\n");
    }
    //Close the railway and power station system
    railway_close();
    PowerStation_A_close();
    PowerStation_B_close();

    /*
    //Wait for keyboard thread to finish before exiting
    pthread_join(keyboardThread,NULL);
    */

	return 0;
}
