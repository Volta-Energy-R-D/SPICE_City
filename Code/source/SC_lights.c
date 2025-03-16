/*********************************************
*
* SPICE City (tm) Lights Source
*
*   items included:
*       
*
* authors:
*           Sharon Fan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/
#include "SC_lights.h"

#include <phidget22.h>
#include <stdio.h>


/*****************************************

local defines

******************************************/
#define ATTACH_WAIT_TIME                    500

// generating station 
#define Lights_GS_0_PH                      657281  // Phidget Hub device serial number
#define Lights_GS_0_PH_LED_chan             0       // Phidget Hub LED channel
#define Lights_GS_1_PH                      657281
#define Lights_GS_1_PH_LED_chan             1

// subway
#define Lights_Subway_0_PH                  657281
#define Lights_Subway_0_PH_LED_chan         2
#define Lights_Subway_1_PH                  657281
#define Lights_Subway_1_PH_LED_chan         3

// gridWISE microgrids 1 & 2
#define Lights_gW_1_0_PH                    657281
#define Lights_gW_1_0_PH_LED_chan           4
#define Lights_gW_1_1_PH                    657281
#define Lights_gW_1_1_PH_LED_chan           5
#define Lights_gW_2_0_PH                    657281
#define Lights_gW_2_0_PH_LED_chan           58
#define Lights_gW_2_1_PH                    657281
#define Lights_gW_2_1_PH_LED_chan           59

// downtown arrondissment A
#define Lights_DT_A_0_PH                    657281
#define Lights_DT_A_0_PH_LED_chan           52
#define Lights_DT_A_1_PH                    657281
#define Lights_DT_A_1_PH_LED_chan           53

// downtown arrondissment B
#define Lights_DT_B_0_PH                    657281
#define Lights_DT_B_0_PH_LED_chan           10
#define Lights_DT_B_1_PH                    657281
#define Lights_DT_B_1_PH_LED_chan           11

// SOCRATES Station A
#define Lights_SOCRATES_A_0_PH              657281
#define Lights_SOCRATES_A_0_PH_LED_chan     12
#define Lights_SOCRATES_A_1_PH              657281
#define Lights_SOCRATES_A_1_PH_LED_chan     13

// Union Station
#define Lights_Union_0_PH                   657281
#define Lights_Union_0_PH_LED_chan          14
#define Lights_Union_1_PH                   657281
#define Lights_Union_1_PH_LED_chan          15

// residential areas A & B
#define Lights_Res_A_0_PH                   657281
#define Lights_Res_A_0_PH_LED_chan          62
#define Lights_Res_A_1_PH                   657281
#define Lights_Res_A_1_PH_LED_chan          63
#define Lights_Res_B_0_PH                   657281
#define Lights_Res_B_0_PH_LED_chan          50
#define Lights_Res_B_1_PH                   657281
#define Lights_Res_B_1_PH_LED_chan          51

// industrial facility
#define Lights_Industry_0_PH                657281
#define Lights_Industry_0_PH_LED_chan       48
#define Lights_Industry_1_PH                657281
#define Lights_Industry_1_PH_LED_chan       49

// commercial medical area
#define Lights_ComMed_0_PH                  657281
#define Lights_ComMed_0_PH_LED_chan         60
#define Lights_ComMed_1_PH                  657281
#define Lights_ComMed_1_PH_LED_chan         61



/*****************************************

local variables

******************************************/

// Declare your Phidget channels and other variables

//  generating station
static PhidgetDigitalOutputHandle Lights_GS_0;
static PhidgetDigitalOutputHandle Lights_GS_1;

//  subway
static PhidgetDigitalOutputHandle Lights_Subway_0;
static PhidgetDigitalOutputHandle Lights_Subway_1;

//  gridWISE microgrids
static PhidgetDigitalOutputHandle Lights_gW_1_0;
static PhidgetDigitalOutputHandle Lights_gW_1_1;
static PhidgetDigitalOutputHandle Lights_gW_2_0;
static PhidgetDigitalOutputHandle Lights_gW_2_1;

//  downtown arrondissments A & B
static PhidgetDigitalOutputHandle Lights_DT_A_0;
static PhidgetDigitalOutputHandle Lights_DT_A_1;
static PhidgetDigitalOutputHandle Lights_DT_B_0;
static PhidgetDigitalOutputHandle Lights_DT_B_1;

//  SOCRATES station A
static PhidgetDigitalOutputHandle Lights_SOCRATES_A_0;
static PhidgetDigitalOutputHandle Lights_SOCRATES_A_1;

//  Union Station
static PhidgetDigitalOutputHandle Lights_Union_0;
static PhidgetDigitalOutputHandle Lights_Union_1;

//  residential areas A & B
static PhidgetDigitalOutputHandle Lights_Res_A_0;
static PhidgetDigitalOutputHandle Lights_Res_A_1;
static PhidgetDigitalOutputHandle Lights_Res_B_0;
static PhidgetDigitalOutputHandle Lights_Res_B_1;

//  industrial facility 
static PhidgetDigitalOutputHandle Lights_Industry_0;
static PhidgetDigitalOutputHandle Lights_Industry_1;

//  commercial-medical area
static PhidgetDigitalOutputHandle Lights_ComMed_0;
static PhidgetDigitalOutputHandle Lights_ComMed_1;

/*****************************************

local functions

******************************************/

// handlers
static void CCONV onLights_GS_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_GS_0 !");
}

static void CCONV onLights_GS_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_GS_0 !");
}

static void CCONV onLights_GS_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_GS_1 !");
}

static void CCONV onLights_GS_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_GS_1 !");
}

static void CCONV onLights_Subway_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Subway_0 !");
}

static void CCONV onLights_Subway_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Subway_0 !");
}

static void CCONV onLights_Subway_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Subway_1 !");
}

static void CCONV onLights_Subway_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Subway_1 !");
}

static void CCONV onLights_gW_1_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_gW_1_0 !");
}

static void CCONV onLights_gW_1_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_gW_1_0 !");
}

static void CCONV onLights_gW_1_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_gW_1_1 !");
}

static void CCONV onLights_gW_1_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_gW_1_1 !");
}

static void CCONV onLights_gW_2_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_gW_2_0 !");
}

static void CCONV onLights_gW_2_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_gW_2_0 !");
}

static void CCONV onLights_gW_2_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_gW_2_1 !");
}

static void CCONV onLights_gW_2_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_gW_2_1 !");
}

static void CCONV onLights_DT_A_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_DT_A_0 !");
}

static void CCONV onLights_DT_A_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_DT_A_0 !");
}

static void CCONV onLights_DT_A_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_DT_A_1 !");
}

static void CCONV onLights_DT_A_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_DT_A_1 !");
}

static void CCONV onLights_DT_B_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_DT_B_0 !");
}

static void CCONV onLights_DT_B_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_DT_B_0 !");
}

static void CCONV onLights_DT_B_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_DT_B_1 !");
}

static void CCONV onLights_DT_B_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_DT_B_1 !");
}

static void CCONV onLights_SOCRATES_A_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_SOCRATES_A_0 !");
}

static void CCONV onLights_SOCRATES_A_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_SOCRATES_A_0 !");
}

static void CCONV onLights_SOCRATES_A_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_SOCRATES_A_1 !");
}

static void CCONV onLights_SOCRATES_A_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_SOCRATES_A_1 !");
}

static void CCONV onLights_Union_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Union_0 !");
}

static void CCONV onLights_Union_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Union_0 !");
}

static void CCONV onLights_Union_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Union_1 !");
}

static void CCONV onLights_Union_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Union_1 !");
}

static void CCONV onLights_Res_A_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Res_A_0 !");
}

static void CCONV onLights_Res_A_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Res_A_0 !");
}

static void CCONV onLights_Res_A_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Res_A_1 !");
}

static void CCONV onLights_Res_A_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Res_A_1 !");
}

static void CCONV onLights_Res_B_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Res_B_0 !");
}

static void CCONV onLights_Res_B_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Res_B_0 !");
}

static void CCONV onLights_Res_B_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Res_B_1 !");
}

static void CCONV onLights_Res_B_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Res_B_1 !");
}

static void CCONV onLights_Industry_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Industry_0 !");
}

static void CCONV onLights_Industry_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Industry_0 !");
}

static void CCONV onLights_Industry_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_Industry_1 !");
}

static void CCONV onLights_Industry_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_Industry_1 !");
}

static void CCONV onLights_ComMed_0_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_ComMed_0 !");
}

static void CCONV onLights_ComMed_0_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_ComMed_0 !");
}

static void CCONV onLights_ComMed_1_Attach(PhidgetHandle ch, void * ctx) {
	printf("Attach Lights_ComMed_1 !");
}

static void CCONV onLights_ComMed_1_Detach(PhidgetHandle ch, void * ctx) {
	printf("Detach Lights_ComMed_1 !");
}


/*****************************************

external or "interface" functions

******************************************/

void CreateSCLights (void) 
{

	//Create your Phidget channels
	PhidgetDigitalOutput_create(&Lights_GS_0);
	PhidgetDigitalOutput_create(&Lights_GS_1);
	PhidgetDigitalOutput_create(&Lights_Subway_0);
	PhidgetDigitalOutput_create(&Lights_Subway_1);
	PhidgetDigitalOutput_create(&Lights_gW_1_0);
	PhidgetDigitalOutput_create(&Lights_gW_1_1);
	PhidgetDigitalOutput_create(&Lights_gW_2_0);
	PhidgetDigitalOutput_create(&Lights_gW_2_1);
	PhidgetDigitalOutput_create(&Lights_DT_A_0);
	PhidgetDigitalOutput_create(&Lights_DT_A_1);
	PhidgetDigitalOutput_create(&Lights_DT_B_0);
	PhidgetDigitalOutput_create(&Lights_DT_B_1);
	PhidgetDigitalOutput_create(&Lights_SOCRATES_A_0);
	PhidgetDigitalOutput_create(&Lights_SOCRATES_A_1);
	PhidgetDigitalOutput_create(&Lights_Union_0);
	PhidgetDigitalOutput_create(&Lights_Union_1);
	PhidgetDigitalOutput_create(&Lights_Res_A_0);
	PhidgetDigitalOutput_create(&Lights_Res_A_1);
	PhidgetDigitalOutput_create(&Lights_Res_B_0);
	PhidgetDigitalOutput_create(&Lights_Res_B_1);
	PhidgetDigitalOutput_create(&Lights_Industry_0);
	PhidgetDigitalOutput_create(&Lights_Industry_1);
	PhidgetDigitalOutput_create(&Lights_ComMed_0);
	PhidgetDigitalOutput_create(&Lights_ComMed_1);

	// Set addressing parameters to specify which channel to open (if any)
	
    //      generating station
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_GS_0, Lights_GS_0_PH);
    Phidget_setChannel((PhidgetHandle)Lights_GS_0, Lights_GS_0_PH_LED_chan);
	Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_GS_1, Lights_GS_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_GS_1, Lights_GS_1_PH_LED_chan);

    //      subway
	Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Subway_0, Lights_Subway_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Subway_0, Lights_Subway_0_PH_LED_chan);
	Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Subway_1, Lights_Subway_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Subway_1, Lights_Subway_1_PH_LED_chan);

    //      gridWISE microgrids 1 & 2
	Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_gW_1_0, Lights_gW_1_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_gW_1_0, Lights_gW_1_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_gW_1_1, Lights_gW_1_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_gW_1_1, Lights_gW_1_1_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_gW_2_0, Lights_gW_2_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_gW_2_0, Lights_gW_2_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_gW_2_1, Lights_gW_2_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_gW_2_1, Lights_gW_2_1_PH_LED_chan);

    //      downtown arrondissements A & B
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_DT_A_0, Lights_DT_A_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_DT_A_0, Lights_DT_A_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_DT_A_1, Lights_DT_A_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_DT_A_1, Lights_DT_A_1_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_DT_B_0, Lights_DT_B_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_DT_B_0, Lights_DT_B_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_DT_B_1, Lights_DT_B_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_DT_B_1, Lights_DT_B_1_PH_LED_chan);

    //      SOCRATES station A
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_SOCRATES_A_0, Lights_SOCRATES_A_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_SOCRATES_A_0, Lights_SOCRATES_A_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_SOCRATES_A_1, Lights_SOCRATES_A_1_PH);
    Phidget_setChannel((PhidgetHandle)Lights_SOCRATES_A_1, Lights_SOCRATES_A_1_PH_LED_chan);

    //      Union Station
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Union_0, Lights_Union_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Union_0, Lights_Union_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Union_1, Lights_Union_1_PH);
    Phidget_setChannel((PhidgetHandle)Lights_Union_1, Lights_Union_1_PH_LED_chan);

    //      residential areas A & B
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Res_A_0, Lights_Res_A_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Res_A_0, Lights_Res_A_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Res_A_1, Lights_Res_A_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Res_A_1, Lights_Res_A_1_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Res_B_0, Lights_Res_B_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Res_B_0, Lights_Res_B_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Res_B_1, Lights_Res_B_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Res_B_1, Lights_Res_B_1_PH_LED_chan);

    //      industrial facility
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Industry_0, Lights_Industry_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_Industry_0, Lights_Industry_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_Industry_1, Lights_Industry_1_PH);
    Phidget_setChannel((PhidgetHandle)Lights_Industry_1, Lights_Industry_1_PH_LED_chan);

    //      commercial medical area
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_ComMed_0, Lights_ComMed_0_PH);
	Phidget_setChannel((PhidgetHandle)Lights_ComMed_0, Lights_ComMed_0_PH_LED_chan);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Lights_ComMed_1, Lights_ComMed_1_PH);
	Phidget_setChannel((PhidgetHandle)Lights_ComMed_1, Lights_ComMed_1_PH_LED_chan);

	//Assign any event handlers you need before calling open so that no events are missed.
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_GS_0, onLights_GS_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_GS_0, onLights_GS_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_GS_1, onLights_GS_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_GS_1, onLights_GS_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Subway_0, onLights_Subway_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Subway_0, onLights_Subway_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Subway_1, onLights_Subway_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Subway_1, onLights_Subway_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_gW_1_0, onLights_gW_1_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_gW_1_0, onLights_gW_1_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_gW_1_1, onLights_gW_1_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_gW_1_1, onLights_gW_1_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_gW_2_0, onLights_gW_2_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_gW_2_0, onLights_gW_2_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_gW_2_1, onLights_gW_2_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_gW_2_1, onLights_gW_2_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_DT_A_0, onLights_DT_A_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_DT_A_0, onLights_DT_A_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_DT_A_1, onLights_DT_A_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_DT_A_1, onLights_DT_A_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_DT_B_0, onLights_DT_B_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_DT_B_0, onLights_DT_B_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_DT_B_1, onLights_DT_B_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_DT_B_1, onLights_DT_B_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_SOCRATES_A_0, onLights_SOCRATES_A_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_SOCRATES_A_0, onLights_SOCRATES_A_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_SOCRATES_A_1, onLights_SOCRATES_A_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_SOCRATES_A_1, onLights_SOCRATES_A_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Union_0, onLights_Union_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Union_0, onLights_Union_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Union_1, onLights_Union_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Union_1, onLights_Union_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Res_A_0, onLights_Res_A_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Res_A_0, onLights_Res_A_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Res_A_1, onLights_Res_A_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Res_A_1, onLights_Res_A_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Res_B_0, onLights_Res_B_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Res_B_0, onLights_Res_B_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Res_B_1, onLights_Res_B_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Res_B_1, onLights_Res_B_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Industry_0, onLights_Industry_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Industry_0, onLights_Industry_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_Industry_1, onLights_Industry_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_Industry_1, onLights_Industry_1_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_ComMed_0, onLights_ComMed_0_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_ComMed_0, onLights_ComMed_0_Detach, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)Lights_ComMed_1, onLights_ComMed_1_Attach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)Lights_ComMed_1, onLights_ComMed_1_Detach, NULL);

	//Open your Phidgets and wait for attachment
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_GS_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_GS_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Subway_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Subway_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_gW_1_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_gW_1_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_gW_2_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_gW_2_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_DT_A_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_DT_A_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_DT_B_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_DT_B_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_SOCRATES_A_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_SOCRATES_A_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Union_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Union_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Res_A_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Res_A_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Res_B_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Res_B_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Industry_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_Industry_1, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_ComMed_0, ATTACH_WAIT_TIME);
	Phidget_openWaitForAttachment((PhidgetHandle)Lights_ComMed_1, ATTACH_WAIT_TIME);

    return;
}


void TurnONLight(const unsigned short int location)
{
    switch (location) {
        case LIGHTS_GS_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_0, 1);
        break;
        case LIGHTS_GS_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_1, 1);
        break; 
        case LIGHTS_SUBWAY_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_0, 1);
        break;
        case LIGHTS_SUBWAY_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_1, 1);
        break;
        case LIGHTS_GW_1_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_0, 1);
        break;
        case LIGHTS_GW_1_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_1, 1);
        break;
        case LIGHTS_GW_2_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_0, 1);
        break;
        case LIGHTS_GW_2_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_1, 1);
        break;
        case LIGHTS_DT_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_0, 1);
        break;
        case LIGHTS_DT_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_1, 1);
        break;
        case LIGHTS_DT_B_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_0, 1);
        break;
        case LIGHTS_DT_B_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_1, 1);
        break;
        case LIGHTS_SOCRATES_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_0, 1);
        break;
        case LIGHTS_SOCRATES_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_1, 1);
        break;
        case LIGHTS_UNION_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_0, 1);
        break;
        case LIGHTS_UNION_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_1, 1);
        break;
        case LIGHTS_RES_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_0, 1);
        break;
        case LIGHTS_RES_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_1, 1);
        break;
        case LIGHTS_RES_B_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_0, 1);
        break;
        case LIGHTS_RES_B_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_1, 1);
        break;
        case LIGHTS_INDUSTRY_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_0, 1);
        break;
        case LIGHTS_INDUSTRY_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_1, 1);
        break;
        case LIGHTS_COMMED_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_0, 1);
        break;
        case LIGHTS_COMMED_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_1, 1);
        break;
        default: // turn on ALL lights
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_1, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_0, 1);
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_1, 1);
        break;
    }
    return;
}

void TurnOFFLight (const unsigned short int location)
{
    switch (location) {
        case LIGHTS_GS_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_0, 0);
        break;
        case LIGHTS_GS_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_1, 0);
        break; 
        case LIGHTS_SUBWAY_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_0, 0);
        break;
        case LIGHTS_SUBWAY_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_1, 0);
        break;
        case LIGHTS_GW_1_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_0, 0);
        break;
        case LIGHTS_GW_1_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_1, 0);
        break;
        case LIGHTS_GW_2_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_0, 0);
        break;
        case LIGHTS_GW_2_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_1, 0);
        break;
        case LIGHTS_DT_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_0, 0);
        break;
        case LIGHTS_DT_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_1, 0);
        break;
        case LIGHTS_DT_B_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_0, 0);
        break;
        case LIGHTS_DT_B_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_1, 0);
        break;
        case LIGHTS_SOCRATES_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_0, 0);
        break;
        case LIGHTS_SOCRATES_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_1, 0);
        break;
        case LIGHTS_UNION_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_0, 0);
        break;
        case LIGHTS_UNION_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_1, 0);
        break;
        case LIGHTS_RES_A_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_0, 0);
        break;
        case LIGHTS_RES_A_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_1, 0);
        break;
        case LIGHTS_RES_B_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_0, 0);
        break;
        case LIGHTS_RES_B_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_1, 0);
        break;
        case LIGHTS_INDUSTRY_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_0, 0);
        break;
        case LIGHTS_INDUSTRY_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_1, 0);
        break;
        case LIGHTS_COMMED_0:
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_0, 0);
        break;
        case LIGHTS_COMMED_1:
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_1, 0);
        break;
        default: // turn on ALL lights
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_GS_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Subway_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_1_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_gW_2_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_A_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_DT_B_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_SOCRATES_A_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Union_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_A_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Res_B_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_Industry_1, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_0, 0);
            PhidgetDigitalOutput_setDutyCycle(Lights_ComMed_1, 0);
        break;
    }
    return;
}

void ShutdownSCLights (void) 
{
	//Close your Phidgets once the program is done.
	Phidget_close((PhidgetHandle)Lights_GS_0);
	Phidget_close((PhidgetHandle)Lights_GS_1);
	Phidget_close((PhidgetHandle)Lights_Subway_0);
	Phidget_close((PhidgetHandle)Lights_Subway_1);
	Phidget_close((PhidgetHandle)Lights_gW_1_0);
	Phidget_close((PhidgetHandle)Lights_gW_1_1);
	Phidget_close((PhidgetHandle)Lights_gW_2_0);
	Phidget_close((PhidgetHandle)Lights_gW_2_1);
	Phidget_close((PhidgetHandle)Lights_DT_A_0);
	Phidget_close((PhidgetHandle)Lights_DT_A_1);
	Phidget_close((PhidgetHandle)Lights_DT_B_0);
	Phidget_close((PhidgetHandle)Lights_DT_B_1);
	Phidget_close((PhidgetHandle)Lights_SOCRATES_A_0);
	Phidget_close((PhidgetHandle)Lights_SOCRATES_A_1);
	Phidget_close((PhidgetHandle)Lights_Union_0);
	Phidget_close((PhidgetHandle)Lights_Union_1);
	Phidget_close((PhidgetHandle)Lights_Res_A_0);
	Phidget_close((PhidgetHandle)Lights_Res_A_1);
	Phidget_close((PhidgetHandle)Lights_Res_B_0);
	Phidget_close((PhidgetHandle)Lights_Res_B_1);
	Phidget_close((PhidgetHandle)Lights_Industry_0);
	Phidget_close((PhidgetHandle)Lights_Industry_1);
	Phidget_close((PhidgetHandle)Lights_ComMed_0);
	Phidget_close((PhidgetHandle)Lights_ComMed_1);

	PhidgetDigitalOutput_delete(&Lights_GS_0);
	PhidgetDigitalOutput_delete(&Lights_GS_1);
	PhidgetDigitalOutput_delete(&Lights_Subway_0);
	PhidgetDigitalOutput_delete(&Lights_Subway_1);
	PhidgetDigitalOutput_delete(&Lights_gW_1_0);
	PhidgetDigitalOutput_delete(&Lights_gW_1_1);
	PhidgetDigitalOutput_delete(&Lights_gW_2_0);
	PhidgetDigitalOutput_delete(&Lights_gW_2_1);
	PhidgetDigitalOutput_delete(&Lights_DT_A_0);
	PhidgetDigitalOutput_delete(&Lights_DT_A_1);
	PhidgetDigitalOutput_delete(&Lights_DT_B_0);
	PhidgetDigitalOutput_delete(&Lights_DT_B_1);
	PhidgetDigitalOutput_delete(&Lights_SOCRATES_A_0);
	PhidgetDigitalOutput_delete(&Lights_SOCRATES_A_1);
	PhidgetDigitalOutput_delete(&Lights_Union_0);
	PhidgetDigitalOutput_delete(&Lights_Union_1);
	PhidgetDigitalOutput_delete(&Lights_Res_A_0);
	PhidgetDigitalOutput_delete(&Lights_Res_A_1);
	PhidgetDigitalOutput_delete(&Lights_Res_B_0);
	PhidgetDigitalOutput_delete(&Lights_Res_B_1);
	PhidgetDigitalOutput_delete(&Lights_Industry_0);
	PhidgetDigitalOutput_delete(&Lights_Industry_1);
	PhidgetDigitalOutput_delete(&Lights_ComMed_0);
	PhidgetDigitalOutput_delete(&Lights_ComMed_1);
    return;
}

