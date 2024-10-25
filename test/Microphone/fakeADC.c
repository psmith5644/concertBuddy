#include "fakeADC.h"
#include <string.h>

sample_t static nextFakeSample;
ADC_STATUS static status;
sample_t fakeContinuousSamples[4] = {0x0, 0x0, 0x0, 0x0};

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

void ADC_ContinuousSamplingBegin(sample_t * dest) {
    status = ADC_STATUS_CONTINUOUS_SAMPLING;

    if (dest == NULL) {
        return;
    }
    
    memcpy(dest, fakeContinuousSamples, 4 * sizeof(sample_t));
}

void ADC_ContinuousSamplingStop(void) {
    status = ADC_STATUS_CONTINUOUS_RDY;
}

void FakeADC_SetBuffer(sample_t * buf) {
    memcpy(fakeContinuousSamples, buf, 4 * sizeof(sample_t));
}