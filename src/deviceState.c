#include "deviceState.h"
#include "pwrSwitch.h"

DeviceState state;

void DeviceState_Init(void) {
    
}

void DeviceState_Destroy(void) {

}

DeviceState DeviceState_GetState(void) {
    return PwrSwitch_GetState();
}