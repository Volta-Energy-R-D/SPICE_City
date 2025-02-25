/*********************************************
*
* SPICE City (tm) Railway Header File
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
#ifndef SC_RAILWAY_HEADER_H  // Header guard
#define SC_RAILWAY_HEADER_H

#include <phidget22.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep
#include <pthread.h> // for threading

/******************************************
*
* DEFINITIONS
*
*******************************************/
#define NUM_RAILWAYS 4

#define SB_Shin_HST_SN 767874
#define SB_Shin_HST_PN 0
#define SB_Shin_HST_CBC 0

#define NB_Shin_HST_SN 767874
#define NB_Shin_HST_PN 0
#define NB_Shin_HST_CBC 1

#define SB_Subway_SN 767874
#define SB_Subway_PN 0
#define SB_Subway_CBC 2

#define NB_Subway_SN 767874
#define NB_Subway_PN 0
#define NB_Subway_CBC 3

#define SB_Shin_TPS_SN 767874
#define SB_Shin_TPS_PN 1

#define NB_Shin_TPS_SN 767874
#define NB_Shin_TPS_PN 2

#define SB_Subway_TPS_SN 767895
#define SB_Subway_TPS_PN 1

#define NB_Subway_TPS_SN 767895
#define NB_Subway_TPS_PN 2

#define TRAINSTOP 10              //seconds
#define Attachment_TIMEOUT 5000   //seconds
#define IRSensor_Threshold 5      //cm
#define IRSensor_CheckRate 500000 //microseconds
#define IRSensor_DataInterval 30 //ms

static const int CB_SNs[NUM_RAILWAYS] = {SB_Shin_HST_SN, NB_Shin_HST_SN, SB_Subway_SN, NB_Subway_SN};
static const int CB_PNs[NUM_RAILWAYS] = {SB_Shin_HST_PN, NB_Shin_HST_PN, SB_Subway_PN, NB_Subway_PN};
static const int CB_CNs[NUM_RAILWAYS] = {SB_Shin_HST_CBC, NB_Shin_HST_CBC, SB_Subway_CBC, NB_Subway_CBC};
static const int TPS_SNs[NUM_RAILWAYS] = {SB_Shin_TPS_SN, NB_Shin_TPS_SN, SB_Subway_TPS_SN, NB_Subway_TPS_SN};
static const int TPS_PNs[NUM_RAILWAYS] = {SB_Shin_TPS_PN, NB_Shin_TPS_PN, SB_Subway_TPS_PN, NB_Subway_TPS_PN};

/******************************************
*
* FUNCTIONS
*
*******************************************/
// Initializes the railway system
void railway_init();
// Starts the railway control loop
void railway_start();
// Closes the railway system
void railway_close();


#endif // SC_RAILWAY_HEADER_H (N.B.: last line of header file!)