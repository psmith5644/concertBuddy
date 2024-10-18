#include "unity.h"
#include "microphoneController.h"
#include "FakeMicrophoneDriver.h"

void setup(void) {

}

void teardown(void) {

}

void testSingleSample(void) {
    MicrophoneController_Init();
    FakeMicrophoneDriver_Init();

    FakeMicrophoneDriver_SetNextSample(1);
    TEST_ASSERT_EQUAL_UINT32(1, MicrophoneController_Sample());

    FakeMicrophoneDriver_Destroy();
    MicrophoneController_Destroy();
}   

void testTwoSamples(void) {
    MicrophoneController_Init();
    FakeMicrophoneDriver_Init();

    FakeMicrophoneDriver_SetNextSample(1);
    TEST_ASSERT_EQUAL_UINT32(1, MicrophoneController_Sample());

    FakeMicrophoneDriver_SetNextSample(12);
    TEST_ASSERT_EQUAL_UINT32(12, MicrophoneController_Sample());

    FakeMicrophoneDriver_Destroy();
    MicrophoneController_Destroy();
}