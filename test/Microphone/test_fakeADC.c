#include "unity.h"
#include "fakeADC.h"

/* 
Test List:
- an initialize continuous function sets the status flag to ready for continuous samples
- continuousSamplingBegin() will begin continuous sampling, sending the data to a buffer via DMA
- continuousSamplingStop() will stop the continuous sampling.
*/

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