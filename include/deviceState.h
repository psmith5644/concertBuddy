#pragma once

typedef enum {
    DeviceState_Off,
    DeviceState_On
} DeviceState;

void DeviceState_Init(void);
void DeviceState_Destroy(void);

DeviceState DeviceState_GetState(void);