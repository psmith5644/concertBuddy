#pragma once

typedef enum {
    PwrSwitch_Open,
    PwrSwitch_Closed, 
    PwrSwitch_Undefined
} PwrSwitchState;

void PwrSwitch_Init(void);
void PwrSwitch_Destroy(void);
PwrSwitchState PwrSwitch_GetState(void);
