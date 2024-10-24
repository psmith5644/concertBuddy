#include "unity.h"
#include "microphoneDriver.h"
#include "fakeADC.h"

uint8_t static const microphonePort = 33;

/* 
Test List:
- continuous sampling results in a destination buffer full of samples
- stopping the continuous sampling results in the buffer being unmodified
- can start, stop, and start continuous sampling and buffer remains consistent.
- driver can only be initialized on GPIOs with an ADC
*/

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

void testTwoSamples(void) {
    FakeADC_SetNextSample(1234);
    TEST_ASSERT_EQUAL_UINT32(1234, MicrophoneDriver_Sample(microphonePort));
    FakeADC_SetNextSample(5678);
    TEST_ASSERT_EQUAL_UINT32(5678, MicrophoneDriver_Sample(microphonePort));
}

void testContinuousSamplingBufferResult(void) {
    micSample_t buf[] = {0x12, 0x34, 0x56, 0x78};
    FakeADC_SetBuffer(buf);

    micSample_t * dest;
    MicrophoneDriver_ContinuousSamplingBegin(dest);
    MicrophoneDriver_ContinuousSamplingStop();
    TEST_ASSERT_EQUAL_UINT32_ARRAY(buf, dest, 4);
}
