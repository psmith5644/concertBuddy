#include "unity.h"
#include "fakeADC.h"

/* 
Test List:
- there is an initialize oneshot function that sets the status flag to ready for oneshot samples
- an initialize continuous function sets the status flag to ready for continuous samples
- continuousSamplingBegin() will begin continuous sampling, sending the data to a buffer via DMA
- continuousSamplingStop() will stop the continuous sampling.
*/

void setup(void) {
    FakeADC_Init();
}

void teardown(void) {
    FakeADC_Destroy();
}

void testNoSampleResultZero(void) {
    TEST_ASSERT_EQUAL_UINT32(0, FakeADC_GetNextSample());
}

void testGetSampleMatchesPreviouslySetSample(void) {
    FakeADC_SetNextSample(1234);
    TEST_ASSERT_EQUAL_UINT32(1234, FakeADC_GetNextSample());
}