#include "unity.h"
#include "microphoneDriver.h"
#include "fakeADC.h"

void setup(void) {

}

void teardown(void) {

}

// driver is responsible for congifuring and initializng ADC/DMA, resulting with data in some buffer in RAM.
// therfore relies on fake ADC
void testInitADC(void) {
    uint8_t microphonePort = 33;
    MicrophoneDriver_Init(microphonePort);

    TEST_ASSERT_EQUAL(ADC_STATUS_RDY, FakeADC_GetStatus(microphonePort));

    MicrophoneDriver_Destroy();
}


// test that it only can be initialized on GPIOs with an ADC