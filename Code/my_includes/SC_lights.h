/*********************************************
*
* SPICE City (tm) Lights Header File
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
#ifndef SC_LIGHTS_HEADER_H  // Header guard
#define SC_LIGHTS_HEADER_H

/******************************************

 DEFINITIONS (for external access to lights)

*******************************************/

// generating station, lights 0 and 1
#define LIGHTS_GS_0             0
#define LIGHTS_GS_1             1

// subway, lights 0 and 1
#define LIGHTS_SUBWAY_0         2
#define LIGHTS_SUBWAY_1         3

// gridWISE microgrid 1, lights 0 and 1
#define LIGHTS_GW_1_0           4
#define LIGHTS_GW_1_1           5

// gridWISE microgrid 2, lights 0 and 1
#define LIGHTS_GW_2_0           6
#define LIGHTS_GW_2_1           7

// downtown, arrondissement A, lights 0 and 1
#define LIGHTS_DT_A_0           8
#define LIGHTS_DT_A_1           9

// downtown, arrondissement B, lights 0 and 1
#define LIGHTS_DT_B_0           10
#define LIGHTS_DT_B_1           11

// SOCRATES station A, lights 0 and 1
#define LIGHTS_SOCRATES_A_0     12
#define LIGHTS_SOCRATES_A_1     13

// Union Station, lights 0 and 1
#define LIGHTS_UNION_0          14
#define LIGHTS_UNION_1          15

// residential area A, lights 0 and 1
#define LIGHTS_RES_A_0          16
#define LIGHTS_RES_A_1          17

// residential area B, lights 0 and 1
#define LIGHTS_RES_B_0          18
#define LIGHTS_RES_B_1          19

// industrial facility (manufacturing), lights 0 and 1
#define LIGHTS_INDUSTRY_0       20
#define LIGHTS_INDUSTRY_1       21

// commercial-medical area, lights 0 and 1
#define LIGHTS_COMMED_0         22
#define LIGHTS_COMMED_1         23

// ALL LIGHTS
#define LIGHTS_ALL              127

/******************************************
*
* FUNCTIONS
*
*******************************************/

void CreateSCLights (void);
void TurnONLight (const unsigned short int location);
void TurnOFFLight (const unsigned short int location);
void ShutdownSCLights (void);






#endif // SC_LIGHTS_HEADER_H (N.B.: last line of header file!)