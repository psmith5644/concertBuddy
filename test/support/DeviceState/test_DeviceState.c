#include "unity.h"
#include "deviceState.h"
#include "fakePwrSwitch.h"

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

void testStateOnWhenSwitchClosed(void) {
    PwrSwitch_Init();
    FakePwrSwitch_Close();

    TEST_ASSERT_EQUAL_UINT8(DeviceState_On, DeviceState_GetState());

    PwrSwitch_Destroy();
}