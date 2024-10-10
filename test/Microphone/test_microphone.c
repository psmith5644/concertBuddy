#include "unity.h"
#include "fakeMic.h"

static micSample * sampleData;

void setup(void) {

}

void teardown() {

}

void testSampleOutput(void) {
    Mic_Init();

    micSample sample = FakeMic_Sample(1);

    TEST_ASSERT_EQUAL_UINT32(1, sample);

    Mic_Destroy();
}

void testTwoSamples(void) {
    Mic_Init();

    TEST_ASSERT_EQUAL_UINT32(1, FakeMic_Sample(1));
    TEST_ASSERT_EQUAL_UINT32(12, FakeMic_Sample(12));

    Mic_Destory();
}