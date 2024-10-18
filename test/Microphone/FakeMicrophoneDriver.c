#include "FakeMicrophoneDriver.h"

uint32_t static nextSample;

uint32_t MicrophoneDriver_Sample(void) {
    return nextSample;
}

void FakeMicrophoneDriver_Init(void) {}
void FakeMicrophoneDriver_Destroy(void) {}
void FakeMicrophoneDriver_SetNextSample(uint32_t sample) {
    nextSample = sample;
}