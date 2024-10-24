#include "fakeADC.h"

sample_t static nextFakeSample;
ADC_STATUS static status;

sample_t ADC_Sample(void) {
    return nextFakeSample;
}

void ADC_Init(void) {
    status = ADC_STATUS_ONESHOT_RDY;
}

void ADC_Destroy(void) {}


void FakeADC_SetNextSample(sample_t sample) {
    nextFakeSample = sample;
}

ADC_STATUS ADC_GetStatus(void) {
    return status;
}

void ADC_InitContinuousSampling(void) {
    status = ADC_STATUS_CONTINUOUS_RDY;
}

