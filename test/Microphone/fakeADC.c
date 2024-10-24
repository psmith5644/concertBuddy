#include "fakeADC.h"

sample_t static nextFakeSample;

sample_t ADC_Sample(void) {
    return nextFakeSample;
}

void FakeADC_Init(void) {}
void FakeADC_Destroy(void) {}

sample_t FakeADC_GetNextSample(void) {
    return nextFakeSample;
}

void FakeADC_SetNextSample(sample_t sample) {
    nextFakeSample = sample;
}
