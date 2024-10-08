#include "unity.h"
#include "deviceState.h"

void setup(void) {

}

void teardown(void) {

}

void testInitStateOff(void) {
    TEST_ASSERT_EQUAL_UINT8(DeviceState_Off, DeviceState_GetState());
}
