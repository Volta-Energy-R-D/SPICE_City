/**************************************************

SC_gridWISE code

software to enable implementation of:

1) gridWISE DERs/microgrids (powered by dedicated external power)

2) High-Demand Intermittent Loads (attached to the main power grid)



****************************************************/
#include <phidget22.h>
#include <stdio.h>


// macros
#define     gW_1_PH                 767874
#define     gW_2_PH                 767874
#define     gW_1_PH_port            0
#define     gW_2_PH_port            0
#define     gW_1_PH_CB_chan         6
#define     gW_2_PH_CB_chan         7

#define     Load5V_1_PH             767874
#define     Load5V_2_PH             767874
#define     Load5V_1_PH_port        0
#define     Load5V_2_PH_port        0
#define     Load5V_1_PB_CB_chan     8
#define     Load5V_2_PB_CB_chan     9


//Declare any event handlers here. These will be called every time the associated event occurs.

static void CCONV onAttach(PhidgetHandle ch, void * ctx) {
    int channel;

    //Getting the channel number to distinguish between Phidgets
    Phidget_getChannel(ch, &channel);
    printf("Attach [%d]!", channel);
}

static void CCONV onDetach(PhidgetHandle ch, void * ctx) {
    int channel;

    //Getting the channel number to distinguish between Phidgets
    Phidget_getChannel(ch, &channel);
    printf("Detach [%d]!", channel);
}

int main() {
    //Declare your Phidget channels and other variables
    PhidgetDigitalOutputHandle digitalOutput6;
    PhidgetDigitalOutputHandle digitalOutput7;
    PhidgetDigitalOutputHandle digitalOutput8;
    PhidgetDigitalOutputHandle digitalOutput9;

    //Create your Phidget channels
    PhidgetDigitalOutput_create(&digitalOutput6);
    PhidgetDigitalOutput_create(&digitalOutput7);
    PhidgetDigitalOutput_create(&digitalOutput8);
    PhidgetDigitalOutput_create(&digitalOutput9);

    //Set addressing parameters to specify which channel to open (if any)
    Phidget_setHubPort((PhidgetHandle)digitalOutput6, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput6, 767874);
    Phidget_setChannel((PhidgetHandle)digitalOutput6, 6);
    Phidget_setHubPort((PhidgetHandle)digitalOutput7, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput7, 767874);
    Phidget_setChannel((PhidgetHandle)digitalOutput7, 7);
    Phidget_setHubPort((PhidgetHandle)digitalOutput8, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput8, 767874);
    Phidget_setChannel((PhidgetHandle)digitalOutput8, 8);
    Phidget_setHubPort((PhidgetHandle)digitalOutput9, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)digitalOutput9, 767874);
    Phidget_setChannel((PhidgetHandle)digitalOutput9, 9);

    //Assign any event handlers you need before calling open so that no events are missed.
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput6, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput6, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput7, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput7, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput8, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput8, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)digitalOutput9, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)digitalOutput9, onDetach, NULL);

    //Open your Phidgets and wait for attachment
    Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput6, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput7, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput8, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)digitalOutput9, 5000);

    //Do stuff with your Phidgets here or in your event handlers.
    PhidgetDigitalOutput_setDutyCycle(digitalOutput6, 1);
    PhidgetDigitalOutput_setDutyCycle(digitalOutput7, 1);
    PhidgetDigitalOutput_setDutyCycle(digitalOutput8, 1);
    PhidgetDigitalOutput_setDutyCycle(digitalOutput9, 1);

    //Wait until Enter has been pressed before exiting
    getchar();

    //Close your Phidgets once the program is done.
    Phidget_close((PhidgetHandle)digitalOutput6);
    Phidget_close((PhidgetHandle)digitalOutput7);
    Phidget_close((PhidgetHandle)digitalOutput8);
    Phidget_close((PhidgetHandle)digitalOutput9);

    PhidgetDigitalOutput_delete(&digitalOutput6);
    PhidgetDigitalOutput_delete(&digitalOutput7);
    PhidgetDigitalOutput_delete(&digitalOutput8);
    PhidgetDigitalOutput_delete(&digitalOutput9);
}
