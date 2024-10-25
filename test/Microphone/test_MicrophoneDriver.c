#include "unity.h"
#include "microphoneDriver.h"
#include "fakeADC.h"

uint8_t static const microphonePort = 33;

/* 
Test List:
- continuous sampling results in a destination buffer full of samples
- stopping the continuous sampling results in the buffer being unmodified
- can start, stop, and start continuous sampling and buffer remains consistent.
- can clear the buffer
- can start continuous sampling without a value to continuously sample
- driver can only be initialized on GPIOs with an ADC
*/

void setUp(void) {
    MicrophoneDriver_Init(microphonePort);
}

void tearDown(void) {
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
    FakeADC_SetBuffer(buf, 4);

    micSample_t dest[] = {0x00, 0x00, 0x00, 0x00};
    MicrophoneDriver_ContinuousSamplingBegin(dest, 4);
    MicrophoneDriver_ContinuousSamplingStop();
    TEST_ASSERT_EQUAL_UINT32_ARRAY(buf, dest, 4);
}

void testMultipleContinuousSamplingBufferResults(void) {
    micSample_t buf[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab};
    FakeADC_SetBuffer(buf, 6);

    micSample_t dest[AUDIO_SAMPLE_BUFFER_SIZE];
    MicrophoneDriver_ContinuousSamplingBegin(dest, 6);
    MicrophoneDriver_ContinuousSamplingStop();

    micSample_t buf2[] = {0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x00, 0x11, 0x22};
    FakeADC_SetBuffer(buf2, 9);
    MicrophoneDriver_ContinuousSamplingBegin(dest, 9);
    MicrophoneDriver_ContinuousSamplingStop();
    
    micSample_t expected[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x00, 0x11, 0x22};
    TEST_ASSERT_EQUAL_UINT32_ARRAY(expected, dest, 15);
}