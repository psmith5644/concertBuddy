#include "unity.h"
#include "fakeADC.h"

void setup(void) {
    ADC_Init();
}

void teardown(void) {
    ADC_Destroy();
}

void testNoSampleResultZero(void) {
    TEST_ASSERT_EQUAL_UINT32(0, ADC_Sample());
}

void testGetSampleMatchesPreviouslySetSample(void) {
    FakeADC_SetNextSample(1234);
    TEST_ASSERT_EQUAL_UINT32(1234, ADC_Sample());
}

void testTwoSamplesMatch(void) {
    FakeADC_SetNextSample(1234);
    TEST_ASSERT_EQUAL_UINT32(1234, ADC_Sample());
    
    FakeADC_SetNextSample(5678);
    TEST_ASSERT_EQUAL_UINT32(5678, ADC_Sample());
}

void testOneshotInitFlag(void) {
    TEST_ASSERT_EQUAL(ADC_STATUS_ONESHOT_RDY, ADC_GetStatus());
}

void testInitContinuousStatus(void) {
    ADC_InitContinuousSampling();
    TEST_ASSERT_EQUAL(ADC_STATUS_CONTINUOUS_RDY, ADC_GetStatus());
}

void testContinuousSamplingBeginFlag(void) {
    ADC_ContinuousSamplingBegin(NULL);
    TEST_ASSERT_EQUAL(ADC_STATUS_CONTINUOUS_SAMPLING, ADC_GetStatus());
}

void testContinuousSamplingStopFlag(void) {
    ADC_ContinuousSamplingStop();
    TEST_ASSERT_EQUAL(ADC_STATUS_CONTINUOUS_RDY, ADC_GetStatus());
}

void testFakeBufferElementsMatch(void) {
    sample_t buf[4] = {0x12, 0x34, 0x56, 0x78};
    FakeADC_SetBuffer(buf);

    sample_t dest[] = {0x0, 0x0, 0x0, 0x0};
    sample_t expected[] = {0x12, 0x34, 0x56, 0x78};

    ADC_ContinuousSamplingBegin(dest);
    ADC_ContinuousSamplingStop();

    TEST_ASSERT_EQUAL_UINT32_ARRAY(expected, dest, 4);
}