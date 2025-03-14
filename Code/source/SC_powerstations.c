/*********************************************
*
* SPICE City (tm) Power Stations Source
*
* 
* authors:
*           Sharon Fan
*           Takis Zourntos
*
* Copyright (C) 2025 Volta Energy
*
**********************************************/
#include "SC_powerstations.h"

#include <phidget22.h>
#include <stdio.h>

// PhidgetVoltageInputHandle voltageInput_A;
// PhidgetVoltageInputHandle voltageInput_B;

static PhidgetDigitalOutputHandle digitalOutput_A;
static PhidgetDigitalOutputHandle digitalOutput_B;

static PhidgetDCMotorHandle dcMotor_A;
static PhidgetDCMotorHandle dcMotor_B;


// Define Generator names
const char* GenerationNames[NUM_DCMOTOR] = {
    "GenerationStation_A",
    "GenerationStation_B"
};

static void CCONV onAttach(PhidgetHandle ch, void * ctx) {
    // int channel;
    // Phidget_getChannel(ch,&channel);

    //int GenerationIndex = *(int*)ctx;
	if (ctx) {
		int GenerationIndex = *(int*)ctx;
		printf("%s: Attach!\n", GenerationNames[GenerationIndex]);
	} else {
		printf("Unknown device attached!\n");
	}
	
	//printf("%s: Attach!\n", GenerationNames[GenerationIndex]);
}

static void CCONV onDetach(PhidgetHandle ch, void * ctx) {
    // int channel;
    // Phidget_getChannel(ch,&channel);

	int GenerationIndex = *(int*)ctx;
	printf("%s: Dettach!\n", GenerationNames[GenerationIndex]);
}

static void CCONV onVoltageChange(PhidgetVoltageInputHandle ch, void * ctx, double voltage) {
	int channel;

	Phidget_getChannel((PhidgetHandle)ch, &channel);
	printf("Voltage [%d]: %lf\n", channel, voltage);
}

void PowerStation_A_init(){
    // PhidgetVoltageInput_create(&voltageInput_A);
	if (PhidgetDCMotor_create(&dcMotor_A) != EPHIDGET_OK) {
		printf("Failed to create dcMotor_A\n");
		return;
	}
	
	if (PhidgetDigitalOutput_create(&digitalOutput_A) != EPHIDGET_OK) {
		printf("Failed to create digitalOutput_A\n");
		return;
	}

    //Set addressing parameters to specify which channel to open
    //VoltageInput Measurement Setup
	// Phidget_setDeviceSerialNumber((PhidgetHandle)voltageInput_A, Gen_Station_A_Vol_SN);
    // Phidget_setHubPort((PhidgetHandle)voltageInput_A, Gen_Station_A_Vol_PN);
    // Phidget_setChannel((PhidgetHandle)voltageInput_A,Gen_Station_A_Vol_CN);

    //DC Motor Speed Control Setup
    Phidget_setDeviceSerialNumber((PhidgetHandle)dcMotor_A, DC_Mot_A_SN);
    Phidget_setHubPort((PhidgetHandle)dcMotor_A, DC_Mot_A_PN);
    
    //Motor Circuit Breaker
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput_A, Cutoff_A_SN);
    Phidget_setHubPort((PhidgetHandle)digitalOutput_A, Cutoff_A_PN);
    Phidget_setChannel((PhidgetHandle)digitalOutput_A, Cutoff_A_CN);

    //Assign any event handlers needed before calling open so that no events are missed.
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput_A, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput_A, onDetach, NULL);
    
	Phidget_setOnAttachHandler((PhidgetHandle)dcMotor_A, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)dcMotor_A, onDetach, NULL);	

	//PhidgetVoltageInput_setOnVoltageChangeHandler(voltageInput_A, onVoltageChange, NULL);
	//PhidgetVoltageInput_setOnVoltageChangeHandler(voltageInput_A, onVoltageChange, NULL);
	
	printf("Power Generation A initialized!\n");
}

void PowerStation_A_start(){
	int res;
	
	res = Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput_A, Attachment_TIMEOUT);
	if (res != EPHIDGET_OK) {
		printf("Error opening digitalOutput_A: %d\n", res);
		return;  // Exit the function to prevent further errors
	}
	
	res = Phidget_openWaitForAttachment((PhidgetHandle)dcMotor_A, Attachment_TIMEOUT);
	if (res != EPHIDGET_OK) {
		printf("Error opening dcMotor_A: %d\n", res);
		return;
	}
	//Phidget_openWaitForAttachment((PhidgetHandle)voltageInput_A, Attachment_TIMEOUT);
	
	if (dcMotor_A == NULL) {
		printf("Error: dcMotor_A is NULL\n");
		return;
	}
	PhidgetDCMotor_setTargetVelocity(dcMotor_A, Motor_A_Speed);
	
	if (digitalOutput_A == NULL) {
		printf("Error: digitalOutput_A is NULL\n");
		return;
	}
	
	printf("Power Generatin A started.\n");
	
}

void PowerStation_A_PowerOn(){
	
	PhidgetDigitalOutput_setDutyCycle(digitalOutput_A, 1);
	printf("Power Generation A POWER ON.\n");
}

void PowerStation_A_PowerOff(){
	PhidgetDigitalOutput_setDutyCycle(digitalOutput_A, 0);

	printf("Power Generatin A POWER OFF.\n");
}

void PowerStation_A_close(){
	//Phidget_close((PhidgetHandle)digitalOutput_A);
	//Phidget_close((PhidgetHandle)dcMotor_A);
	//Phidget_close((PhidgetHandle)voltageInput_A);

	//PhidgetDigitalOutput_delete(&digitalOutput_A);
	//PhidgetDCMotor_delete(&dcMotor_A);
	//PhidgetVoltageInput_delete(&voltageInput_A);

	if (digitalOutput_A != NULL) {
        Phidget_close((PhidgetHandle)digitalOutput_A);
        PhidgetDigitalOutput_delete(&digitalOutput_A);
    }

    if (dcMotor_A != NULL) {
        Phidget_close((PhidgetHandle)dcMotor_A);
        PhidgetDCMotor_delete(&dcMotor_A);
    }

	printf("Power Generatin A closed.\n");
}

void PowerStation_B_init(){
	//PhidgetVoltageInput_create(&voltageInput_B);
    // PhidgetDCMotor_create(&dcMotor_B);
    // PhidgetDigitalOutput_create(&digitalOutput_B);
	
    if (PhidgetDCMotor_create(&dcMotor_B) != EPHIDGET_OK) {
		printf("Failed to create dcMotor_B\n");
		return;
	}
	
	if (PhidgetDigitalOutput_create(&digitalOutput_B) != EPHIDGET_OK) {
		printf("Failed to create digitalOutput_B\n");
		return;
	}
	
    //Set addressing parameters to specify which channel to open
    //VoltageInput Measurement Setup
	//Phidget_setDeviceSerialNumber((PhidgetHandle)voltageInput_B, Gen_Station_B_Vol_SN);
    //Phidget_setHubPort((PhidgetHandle)voltageInput_B, Gen_Station_B_Vol_PN);
    //Phidget_setChannel((PhidgetHandle)voltageInput_B,Gen_Station_B_Vol_CN);
	
    //DC Motor Speed Control Setup
    Phidget_setDeviceSerialNumber((PhidgetHandle)dcMotor_B, DC_Mot_B_SN);
    Phidget_setHubPort((PhidgetHandle)dcMotor_B, DC_Mot_B_PN);
    
    //Motor Circuit Breaker
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput_B, Cutoff_B_SN);
    Phidget_setHubPort((PhidgetHandle)digitalOutput_B, Cutoff_B_PN);
    Phidget_setChannel((PhidgetHandle)digitalOutput_B, Cutoff_B_CN);

    //Assign any event handlers needed before calling open so that no events are missed.
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput_B, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput_B, onDetach, NULL);
    
	Phidget_setOnAttachHandler((PhidgetHandle)dcMotor_B, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)dcMotor_B, onDetach, NULL);	

	//PhidgetVoltageInput_setOnVoltageChangeHandler(voltageInput_B, onVoltageChange, NULL);
	//PhidgetVoltageInput_setOnVoltageChangeHandler(voltageInput_B, onVoltageChange, NULL);

	printf("Power Generation B initialized!\n");
}

void PowerStation_B_start(){
	int res;

	res = Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput_B, Attachment_TIMEOUT);
	if (res != EPHIDGET_OK) {
		printf("Error opening digitalOutput_B: %d\n", res);
		return;  // Exit the function to prevent further errors
	}

	res = Phidget_openWaitForAttachment((PhidgetHandle)dcMotor_B, Attachment_TIMEOUT);
	if (res != EPHIDGET_OK) {
		printf("Error opening dcMotor_B: %d\n", res);
		return;
	}
	//Phidget_openWaitForAttachment((PhidgetHandle)voltageInput_B, Attachment_TIMEOUT);
	
	if (dcMotor_B == NULL) {
		printf("Error: dcMotor_B is NULL\n");
		return;
	}
	
	PhidgetDCMotor_setTargetVelocity(dcMotor_B, Motor_B_Speed);
	
	if (digitalOutput_B == NULL) {
		printf("Error: digitalOutput_B is NULL\n");
		return;
	}

	PhidgetDigitalOutput_setDutyCycle(digitalOutput_B, 1);

	printf("Power Generatin B started.\n");
}
/*
void PowerStation_B_close(){
	Phidget_close((PhidgetHandle)digitalOutput_B);
	Phidget_close((PhidgetHandle)dcMotor_B);
	//Phidget_close((PhidgetHandle)voltageInput_B);

	PhidgetDigitalOutput_delete(&digitalOutput_B);
	PhidgetDCMotor_delete(&dcMotor_B);
	//PhidgetVoltageInput_delete(&voltageInput_B);
	printf("Power Generatin B closed.\n");
}
*/
void PowerStation_B_PowerOn(){
	
	PhidgetDigitalOutput_setDutyCycle(digitalOutput_B, 1);
	printf("Power Generation B POWER ON.\n");
}

void PowerStation_B_PowerOff(){
	PhidgetDigitalOutput_setDutyCycle(digitalOutput_B, 0);

	printf("Power Generatin B POWER OFF.\n");
}

void PowerStation_B_close() {
    if (digitalOutput_B != NULL) {
        Phidget_close((PhidgetHandle)digitalOutput_B);
        PhidgetDigitalOutput_delete(&digitalOutput_B);
    }

    if (dcMotor_B != NULL) {
        Phidget_close((PhidgetHandle)dcMotor_B);
        PhidgetDCMotor_delete(&dcMotor_B);
    }

    printf("Power Generation B closed.\n");
}


