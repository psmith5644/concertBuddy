#include "unity.h"
#include "microphoneDriver.h"
#include "fakeADC.h"

uint8_t static const microphonePort = 33;

void setup(void) {
    MicrophoneDriver_Init(microphonePort);
}

void teardown(void) {
    MicrophoneDriver_Destroy(microphonePort);
}

// driver is responsible for congifuring and initializng ADC/DMA, resulting with data in some buffer in RAM.
void testInitDriver(void) {
    TEST_ASSERT_EQUAL(MIC_STATUS_RDY, MicrophoneDriver_GetStatus(microphonePort));
}

void testSingleSample(void) {
    FakeADC_SetNextSample(1234);
    micSample_t sample = MicrophoneDriver_Sample(microphonePort);
    TEST_ASSERT_EQUAL_UINT32(1234, sample);
}


// test that it only can be initialized on GPIOs with an ADC