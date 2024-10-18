#include "unity.h"
#include "FakeMicrophoneDriver.h"

void setup(void) {

}

void teardown(void) {

}

void testSingleSample(void) {
    MicrophoneInterface_Init();
    FakeMicrophoneDriver_Init();

    FakeMicrophoneDriver_SetNextSample(1);
    TEST_ASSERT_EQUAL_UINT32(1, MicrophoneInterface_Sample());

    FakeMicrophoneDriver_Destroy();
    MicrophoneInterface_Destroy();
}   