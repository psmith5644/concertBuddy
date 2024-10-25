#include "fakeADC.h"
#include <string.h>

sample_t static nextFakeSample;
ADC_STATUS static status;
sample_t fakeContinuousSamples[AUDIO_SAMPLE_BUFFER_SIZE] = {0x0};
uint32_t static numSamplesInDest;

sample_t ADC_Sample(void) {
    return nextFakeSample;
}

void ADC_Init(void) {
    status = ADC_STATUS_ONESHOT_RDY;
    numSamplesInDest = 0;
}

void ADC_Destroy(void) {
    memset(fakeContinuousSamples, 0xffffffff, AUDIO_SAMPLE_BUFFER_SIZE);
    numSamplesInDest = 0;
}


void FakeADC_SetNextSample(sample_t sample) {
    nextFakeSample = sample;
}

ADC_STATUS ADC_GetStatus(void) {
    return status;
}

void ADC_InitContinuousSampling(void) {
    status = ADC_STATUS_CONTINUOUS_RDY;
}

void ADC_ContinuousSamplingBegin(sample_t * dest, size_t size) {
    status = ADC_STATUS_CONTINUOUS_SAMPLING;

    if (dest == NULL) {
        return;
    }

    memcpy(&dest[numSamplesInDest], fakeContinuousSamples, size * sizeof(sample_t));
    numSamplesInDest += size;
}

void ADC_ContinuousSamplingStop(void) {
    status = ADC_STATUS_CONTINUOUS_RDY;
}

void FakeADC_SetBuffer(sample_t * buf, size_t size) {
    memcpy(fakeContinuousSamples, buf, size * sizeof(sample_t));
}