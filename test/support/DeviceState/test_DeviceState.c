#include "unity.h"
#include "deviceState.h"

void setup(void) {
    DeviceState_Init();
}

void teardown(void) {
    DeviceState_Destroy();
}

void testInitStateOff(void) {
    TEST_ASSERT_EQUAL_UINT8(DeviceState_Off, DeviceState_GetState());
}

void testStateOffWhenSwitchOpen(void) {
    PwrSwitch_Init();
    FakePwrSwitch_Open();

    TEST_ASSERT_EQUAL_UINT8(DeviceState_Off, DeviceState_GetState());

    PwrSwitch_Destroy();
}