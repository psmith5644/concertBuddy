#include "unity.h"
#include "fakeADC.h"

/* 
Test List:
- the getnextsample() function returns whatever was the previous value in setnextsample()
- there is an initialize oneshot function that sets the status flag to ready for oneshot samples
- an initialize continuous function sets the status flag to ready for continuous samples
- continuousSamplingBegin() will begin continuous sampling, sending the data to a buffer via DMA
- continuousSamplingStop() will stop the continuous sampling.
*/

void setup(void) {

}

void teardown(void) {

}

void testNoSampleResultZero(void) {
    FakeADC_Init();

    TEST_ASSERT_EQUAL_UINT32(0, FakeADC_GetNextSample());

    FakeADC_Destroy();
}

void testGetSampleMatchesPreviouslySetSample(void) {
    FakeADC_Init();

    FakeADC_SetNextSample(1234);
    TEST_ASSERT_EQUAL_UINT32(1234, FakeADC_GetNextSample());

    FakeADC_Destroy();
}