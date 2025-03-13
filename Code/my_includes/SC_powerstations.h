/*********************************************
*
* SPICE City (tm) Power Stations Header File
*
*   items included:
*
* authors:
*           Sharon Fan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/
#ifndef SC_POWERSTATIONS_HEADER_H  // Header guard
#define SC_POWERSTATIONS_HEADER_H

#include <phidget22.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep

/******************************************
*
* DEFINITIONS
*
*******************************************/
#define NUM_DCMOTOR 2

#define DC_Mot_A_SN 767874
#define DC_Mot_A_PN 5
#define DC_Mot_B_SN 767895
#define DC_Mot_B_PN 5
#define Cutoff_A_SN 767874
#define Cutoff_A_PN 0
#define Cutoff_A_CN 4
#define Cutoff_B_SN 767874
#define Cutoff_B_PN 0
#define Cutoff_B_CN 5
#define Gen_Station_A_Vol_SN 767874
#define Gen_Station_A_Vol_PN 4
#define Gen_Station_A_Vol_CN 0
#define Gen_Station_B_Vol_SN 767874
#define Gen_Station_B_Vol_PN 4
#define Gen_Station_B_Vol_CN 4


#define Motor_A_Speed 1
#define Motor_B_Speed 1

#define Attachment_TIMEOUT 500   //seconds

static const int DCMotor_SNs[NUM_DCMOTOR] = {DC_Mot_A_SN, DC_Mot_B_SN};
static const int DCMotor_PNs[NUM_DCMOTOR] = {DC_Mot_A_PN, DC_Mot_B_PN};
static const int Cutoff_SNs[NUM_DCMOTOR] = {Cutoff_A_SN, Cutoff_B_SN};
static const int Cutoff_PNs[NUM_DCMOTOR] = {Cutoff_A_PN, Cutoff_B_PN};
static const int Cutoff_CNs[NUM_DCMOTOR] = {Cutoff_A_CN, Cutoff_B_CN};
static const int Gen_Station_Vol_SNs[NUM_DCMOTOR] = {Gen_Station_A_Vol_SN, Gen_Station_B_Vol_SN};
static const int Gen_Station_Vol_PNs[NUM_DCMOTOR] = {Gen_Station_A_Vol_PN, Gen_Station_B_Vol_PN};
static const int Gen_Station_Vol_CNs[NUM_DCMOTOR] = {Gen_Station_A_Vol_CN, Gen_Station_B_Vol_CN};


/******************************************
*
* FUNCTIONS
*
*******************************************/
// Initialize the power station
void PowerStation_A_init();
void PowerStation_B_init();

// Start the power station
void PowerStation_A_start();
void PowerStation_B_start();

// End the power station
void PowerStation_A_close();
void PowerStation_B_close();



#endif // SC_POWERSTATIONS_HEADER_H (N.B.: last line of header file!)