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
#include<pthread.h>

// SPICE-City-specific includes
#include<phidget22.h>
#include "SC_powerstations.h"

volatile int KeepRunning = 1; //flag to control infinite looping
volatile int count = 0;

// Keyboard Intteruption
void* monitor_keyboard(void* arg) {
    printf("Press Enter to stop the railway system and power station system...\n");
    getchar(); // Wait for user to press Enter
    KeepRunning = 0; // Signal to stop the loop
    return NULL;
}

int main(void)
{
	/* initialize workspace
    */
    // railway_init();
    // railway_start();
    // PowerStation_A_init();
    PowerStation_B_init();
    // PowerStation_A_start();
    PowerStation_B_start();
    PowerStation_B_PowerOn();
    // Create a seperate thread to listen for keyboard input for interruption
    pthread_t keyboardThread;
    pthread_create(&keyboardThread, NULL, monitor_keyboard,NULL);

    while (KeepRunning)
	{ 
        sleep(1); //Sleep to prevent CPU overuse
    }
    
    PowerStation_B_PowerOff();
    
    // PowerStation_A_close();
    PowerStation_B_close();

    //Wait for keyboard thread to finish before exiting
    pthread_join(keyboardThread,NULL);

	return 0;
}
