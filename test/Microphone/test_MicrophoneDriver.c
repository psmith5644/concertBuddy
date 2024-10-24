#include "unity.h"
#include "microphoneDriver.h"

void setup(void) {

}

void teardown(void) {

}

// driver is responsible for congifuring and initializng ADC/DMA, resulting with data in some buffer in RAM.
void testInitDriver(void) {
    uint8_t microphonePort = 33;
    MicrophoneDriver_Init(microphonePort);

    TEST_ASSERT_EQUAL(MIC_STATUS_RDY, MicrophoneDriver_GetStatus(microphonePort));

    MicrophoneDriver_Destroy(microphonePort);
}


// test that it only can be initialized on GPIOs with an ADC