/*********************************************
*
* SPICE City (tm) Infrastructure Header File
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
#ifndef SC_INFRASTRUCTURE_HEADER_H  // Header guard
#define SC_INFRASTRUCTURE_HEADER_H

#define EMERGENCY_PH            767895
#define EMERGENCY_PH_port       0

#include<stdio.h>
#include<phidget22.h>
/******************************************
*
* EMERGENCY button code
*
*
*******************************************/
static void CCONV onEMERGENCY_StateChange(PhidgetDigitalInputHandle ch, void * ctx, int state);
static void CCONV onEMERGENCY_Attach(PhidgetHandle ch, void * ctx);
static void CCONV onEMERGENCY_Detach(PhidgetHandle ch, void * ctx);












#endif // SC_INFRASTRUCTURE_HEADER_H (N.B.: last line of header file!)