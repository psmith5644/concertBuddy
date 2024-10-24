#include "fakeADC.h"

sample_t static nextFakeSample;

sample_t ADC_Sample(void) {
    return nextFakeSample;
}

void ADC_Init(void) {}
void ADC_Destroy(void) {}


void FakeADC_SetNextSample(sample_t sample) {
    nextFakeSample = sample;
}

ADC_STATUS ADC_GetStatus(void) {
    return ADC_STATUS_ONESHOT_RDY;
}

