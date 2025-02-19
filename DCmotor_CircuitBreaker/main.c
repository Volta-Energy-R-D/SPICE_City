#include <phidget22.h>
#include <stdio.h>
#include <unistd.h>
#define DataInterval_Distance_Sensor 10 
#define Time_WAIT_FOR_ATTACHMENT 5000

//Declare any event handlers here. These will be called every time the associated event occurs.
static void CCONV onSensorChange(PhidgetVoltageRatioInputHandle ch, void * ctx, double sensorValue, Phidget_UnitInfo * sensorUnit) {
	printf("SensorValue: %lf\n", sensorValue);
	printf("SensorUnit: %s\n", sensorUnit->symbol);
	printf("----------\n");
}

static void CCONV onAttach(PhidgetHandle ch, void * ctx) {
	printf("Attach!\n");
}

static void CCONV onDetach(PhidgetHandle ch, void * ctx) {
	printf("Detach!\n");
}

int main() {
	//Declare your Phidget channels and other variables
	PhidgetDCMotorHandle dcMotor0;
	PhidgetDigitalOutputHandle digitalOutput0;
	PhidgetVoltageRatioInputHandle voltageRatioInput0;

	//Create your Phidget channels
	PhidgetDCMotor_create(&dcMotor0);
	PhidgetDigitalOutput_create(&digitalOutput0);
	PhidgetVoltageRatioInput_create(&voltageRatioInput0);

	//Set addressing parameters to specify which channel to open (if any)
	//DC Motor Control
	Phidget_setHubPort((PhidgetHandle)dcMotor0, 2);
	Phidget_setDeviceSerialNumber((PhidgetHandle)dcMotor0, 767895);
	//Circuit Breakers
	Phidget_setHubPort((PhidgetHandle)digitalOutput0, 1);
	Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput0, 767895);
	//Distance Sensor
	Phidget_setIsHubPortDevice((PhidgetHandle)voltageRatioInput0, 1);
	Phidget_setHubPort((PhidgetHandle)voltageRatioInput0, 0);
	Phidget_setDeviceSerialNumber((PhidgetHandle)voltageRatioInput0, 767895);

	//Assign any event handlers you need before calling open so that no events are missed.
	Phidget_setOnAttachHandler((PhidgetHandle)dcMotor0, onAttach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)dcMotor0, onDetach, NULL);

	Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput0, onAttach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput0, onDetach, NULL);

	PhidgetVoltageRatioInput_setOnSensorChangeHandler(voltageRatioInput0, onSensorChange, NULL);
	Phidget_setOnAttachHandler((PhidgetHandle)voltageRatioInput0, onAttach, NULL);
	Phidget_setOnDetachHandler((PhidgetHandle)voltageRatioInput0, onDetach, NULL);

	//Open your Phidgets and wait for attachment
	Phidget_openWaitForAttachment((PhidgetHandle)dcMotor0, Time_WAIT_FOR_ATTACHMENT);
	Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput0, Time_WAIT_FOR_ATTACHMENT);
	Phidget_openWaitForAttachment((PhidgetHandle)voltageRatioInput0, Time_WAIT_FOR_ATTACHMENT);
	Phidget_setDataInterval((PhidgetHandle)voltageRatioInput0, DataInterval_Distance_Sensor);

	//Do stuff with your Phidgets here or in your event handlers.
	PhidgetDCMotor_setTargetVelocity(dcMotor0, -0.25);
	PhidgetDigitalOutput_setDutyCycle(digitalOutput0, 1);
	//Set the sensor type to match the analog sensor you are using after opening the Phidget
	PhidgetVoltageRatioInput_setSensorType(voltageRatioInput0, SENSOR_TYPE_1101_SHARP_2D120X);
	// PhidgetDigitalOutput_setState(digitalOutput0, 0);
	sleep(10);
	PhidgetDigitalOutput_setDutyCycle(digitalOutput0, 0);
	// PhidgetDigitalOutput_setState(digitalOutput0, -1);

	//Wait until Enter has been pressed before exiting
	getchar();

	//Close your Phidgets once the program is done.
	Phidget_close((PhidgetHandle)dcMotor0);
	Phidget_close((PhidgetHandle)digitalOutput0);
	Phidget_close((PhidgetHandle)voltageRatioInput0);

	PhidgetDCMotor_delete(&dcMotor0);
	PhidgetDigitalOutput_delete(&digitalOutput0);
	PhidgetVoltageRatioInput_delete(&voltageRatioInput0);

}

