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


//Declare your Phidget channels and other variables
static  PhidgetDigitalOutputHandle gW_1;
static  PhidgetDigitalOutputHandle gW_2;
static  PhidgetDigitalOutputHandle Load5V_1;
static  PhidgetDigitalOutputHandle Load5V_2;


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



    //Create your Phidget channels
    PhidgetDigitalOutput_create(&gW_1);
    PhidgetDigitalOutput_create(&gW_2);
    PhidgetDigitalOutput_create(&Load5V_1);
    PhidgetDigitalOutput_create(&Load5V_2);

    //Set addressing parameters to specify which channel to open (if any)
    Phidget_setHubPort((PhidgetHandle)gW_1, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)gW_1, 767874);
    Phidget_setChannel((PhidgetHandle)gW_1, 6);
    Phidget_setHubPort((PhidgetHandle)gW_2, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)gW_2, 767874);
    Phidget_setChannel((PhidgetHandle)gW_2, 7);
    Phidget_setHubPort((PhidgetHandle)Load5V_1, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Load5V_1, 767874);
    Phidget_setChannel((PhidgetHandle)Load5V_1, 8);
    Phidget_setHubPort((PhidgetHandle)Load5V_2, 0);
    Phidget_setDeviceSerialNumber((PhidgetHandle)Load5V_2, 767874);
    Phidget_setChannel((PhidgetHandle)Load5V_2, 9);

    //Assign any event handlers you need before calling open so that no events are missed.
    Phidget_setOnAttachHandler((PhidgetHandle)gW_1, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)gW_1, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)gW_2, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)gW_2, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)Load5V_1, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)Load5V_1, onDetach, NULL);
    Phidget_setOnAttachHandler((PhidgetHandle)Load5V_2, onAttach, NULL);
    Phidget_setOnDetachHandler((PhidgetHandle)Load5V_2, onDetach, NULL);

    //Open your Phidgets and wait for attachment
    Phidget_openWaitForAttachment((PhidgetHandle)gW_1, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)gW_2, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)Load5V_1, 5000);
    Phidget_openWaitForAttachment((PhidgetHandle)Load5V_2, 5000);

    //Do stuff with your Phidgets here or in your event handlers.
    PhidgetDigitalOutput_setDutyCycle(gW_1, 1);
    PhidgetDigitalOutput_setDutyCycle(gW_2, 1);
    PhidgetDigitalOutput_setDutyCycle(Load5V_1, 1);
    PhidgetDigitalOutput_setDutyCycle(Load5V_2, 1);

    
    //Close your Phidgets once the program is done.
    Phidget_close((PhidgetHandle)gW_1);
    Phidget_close((PhidgetHandle)gW_2);
    Phidget_close((PhidgetHandle)Load5V_1);
    Phidget_close((PhidgetHandle)Load5V_2);

    PhidgetDigitalOutput_delete(&gW_1);
    PhidgetDigitalOutput_delete(&gW_2);
    PhidgetDigitalOutput_delete(&Load5V_1);
    PhidgetDigitalOutput_delete(&Load5V_2);

