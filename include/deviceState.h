#pragma once

typedef enum {
    DeviceState_Off
} DeviceState;

DeviceState DeviceState_GetState(void);