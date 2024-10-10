#include "fakePwrSwitch.h"

PwrSwitchState static state;

void PwrSwitch_Init(void) {
    state = PwrSwitch_Undefined;
}

void PwrSwitch_Destroy(void) {

}

PwrSwitchState PwrSwitch_GetState(void) {
    return state;
}

void FakePwrSwitch_Open(void) {
    state = PwrSwitch_Open;
}

void FakePwrSwitch_Close(void) {
    state = PwrSwitch_Closed;
}



