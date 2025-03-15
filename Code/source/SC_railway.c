/*********************************************
*
* SPICE City (tm) Railway Source
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
#include "SC_railway.h"

//Declare your Phidget channels and other variables
PhidgetDigitalOutputHandle digitalOutputs[NUM_RAILWAYS];
PhidgetVoltageRatioInputHandle sensors[NUM_RAILWAYS];

// Define railway names
const char* railwayNames[NUM_RAILWAYS] = {
    "SouthBound_Shin",
    "NouthBound_Shin",
    "SouthBound_Subway",
    "NouthBound_Subway"
};

// Define distance IR sensor names
const char* sensorNames[NUM_RAILWAYS] = {
    "SouthBound_Shin",
    "NouthBound_Shin",
    "SouthBound_Subway",
    "NouthBound_Subway"
};

int stateflag = 0;
int checkno = 0;

static void CCONV onAttach(PhidgetHandle ch, void * ctx) {

    int railwayIndex = *(int*)ctx;
	printf("%s: Attach!\n", sensorNames[railwayIndex]);
}

static void CCONV onDetach(PhidgetHandle ch, void * ctx) {

	int railwayIndex = *(int*)ctx;
	printf("%s: Dettach!\n", sensorNames[railwayIndex]);
}

void railway_system_power_off() {
    printf("Powering off the entire railway system...\n");
    for (int i = 0; i < NUM_RAILWAYS; i++) {
        PhidgetDigitalOutput_setDutyCycle(digitalOutputs[i], 0);  // Power off all trains
        printf("Railway %s: Train power off.\n", railwayNames[i]);
    }
}

void railway_system_power_on() {
    printf("Restoring power to the entire railway system...\n");
    for (int i = 0; i < NUM_RAILWAYS; i++) {
        PhidgetDigitalOutput_setDutyCycle(digitalOutputs[i], 1);  // Power on all trains
        printf("Railway %s: Train power restored.\n", railwayNames[i]);
    }
}

static void CCONV onSensorChange(PhidgetVoltageRatioInputHandle ch, void * ctx, double sensorValue, Phidget_UnitInfo * sensorUnit) {
	int railwayIndex = *(int*)ctx;

    if(sensorValue < IRSensor_Threshold){ 
        printf("Railway %s: Train Detected..Waiting for clearance...\n", railwayNames[railwayIndex]);
        if (stateflag == 0 && checkno == 2){
            stateflag = 1;
            checkno = 0;
        } else if (stateflag == 0 && checkno == 0){
            checkno = checkno + 1;
        } else if (stateflag == 0 && checkno == 1){
            checkno = checkno + 1;
        } else if (stateflag == 1){
            stateflag = 0;
            printf("Railway %s: Train, stopping power.\n", railwayNames[railwayIndex]);
            PhidgetDigitalOutput_setDutyCycle(digitalOutputs[railwayIndex], 0); // Power off the train
    
            sleep(TRAINSTOP);
            PhidgetDigitalOutput_setDutyCycle(digitalOutputs[railwayIndex],1); // Power on the train
            printf("Railway %s: Train power restored .\n", railwayNames[railwayIndex]);

        }
    // printf("SensorValue: %lf\n", sensorValue);
	// printf("SensorUnit: %s\n", sensorUnit->symbol);
	// printf("----------\n");
    }
}

void railway_init(){

    //Create your Phidget channels
    for (int i=0;i<NUM_RAILWAYS;i++){
        PhidgetDigitalOutput_create(&digitalOutputs[i]);
        PhidgetVoltageRatioInput_create(&sensors[i]);

        //Set addressing parameters to specify which channel to open (if any)
        // Distance IR sensor
        Phidget_setIsHubPortDevice((PhidgetHandle)sensors[i], 1);
        Phidget_setHubPort((PhidgetHandle)sensors[i], TPS_PNs[i]);
        Phidget_setDeviceSerialNumber((PhidgetHandle)sensors[i], TPS_SNs[i]);
        // Circuit Breaker
        Phidget_setHubPort((PhidgetHandle)digitalOutputs[i], CB_PNs[i]);
        Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutputs[i], CB_SNs[i]);
        Phidget_setChannel((PhidgetHandle)digitalOutputs[i], CB_CNs[i]);

        //Assign any event handlers needed before calling open so that no events are missed.
        Phidget_setOnAttachHandler((PhidgetHandle)digitalOutputs[i], onAttach, &i);
        Phidget_setOnDetachHandler((PhidgetHandle)digitalOutputs[i], onDetach, &i);
        Phidget_setOnAttachHandler((PhidgetHandle)sensors[i], onAttach, &i);
        Phidget_setOnDetachHandler((PhidgetHandle)sensors[i], onDetach, &i);
        
        PhidgetVoltageRatioInput_setSensorType(sensors[i], SENSOR_TYPE_1101_SHARP_2D120X);
	    PhidgetVoltageRatioInput_setOnSensorChangeHandler(sensors[i], onSensorChange, &i);
    }
}

void railway_start(){
    for (int i =0; i<NUM_RAILWAYS; i++){
        //Open your Phidgets and wait for attachment
	    Phidget_openWaitForAttachment((PhidgetHandle)sensors[i], Attachment_TIMEOUT);
	    Phidget_openWaitForAttachment((PhidgetHandle)digitalOutputs[i], Attachment_TIMEOUT);
	    Phidget_setDataInterval((PhidgetHandle)sensors[i], IRSensor_DataInterval);
    }
    printf("Railway system started.\n");
}

void railway_close(){
    for (int i =0; i<NUM_RAILWAYS; i++){
        //Close your Phidgets once the program is done.
	    Phidget_close((PhidgetHandle)sensors[i]);
	    Phidget_close((PhidgetHandle)digitalOutputs[i]);

	    PhidgetDigitalOutput_delete(&digitalOutputs[i]);
	    PhidgetVoltageRatioInput_delete(&sensors[i]);
    }
    printf("Railway system closed.\n");
}

