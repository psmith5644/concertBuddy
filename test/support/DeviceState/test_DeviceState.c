#include "unity.h"
#include "deviceState.h"
#include "fakePwrSwitch.h"

void setup(void) {
    DeviceState_Init();
    PwrSwitch_Init();
}

void teardown(void) {
    DeviceState_Destroy();
    PwrSwitch_Destroy();
}

void testInitStateOff(void) {
    TEST_ASSERT_EQUAL_UINT8(DeviceState_Off, DeviceState_GetState());
}

void testStateOffWhenSwitchOpen(void) {
    FakePwrSwitch_Open();

    TEST_ASSERT_EQUAL_UINT8(DeviceState_Off, DeviceState_GetState());
}

void testStateOnWhenSwitchClosed(void) {
    FakePwrSwitch_Close();

    TEST_ASSERT_EQUAL_UINT8(DeviceState_On, DeviceState_GetState());
}