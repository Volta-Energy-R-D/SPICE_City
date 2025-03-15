/************************************************** 

SC_gridWISE code

software to enable implementation of:

1) gridWISE DERs/microgrids (powered by dedicated external power)

2) High-Demand Intermittent Loads (attached to the main power grid)



****************************************************/
#ifndef SC_GRIDWISE_HEADER_H  // Header guard
#define SC_GRIDWISE_HEADER_H


/*****************************************

interface defines (move to header file)

******************************************/
#define     ON                      1
#define     OFF                     0

#define     gW_1_channel            6
#define     gW_2_channel            7
#define     Load5V_1_channel        8
#define     Load5V_2_channel        9


/**************************************************************
 
 interface functions
 
 ******************************************************************/

void CreateSCgridWISE(void);
void SC_gridWISE_CONNECT(int channel, const short unsigned int ONorOFF);
void ShutdownSCgridWISE(void);



#endif
