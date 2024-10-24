#include "microphoneDriver.h"

void MicrophoneDriver_Init(uint8_t port) {}
void MicrophoneDriver_Destroy(uint8_t port) {}

MIC_STATUS MicrophoneDriver_GetStatus(uint8_t port) {
    return MIC_STATUS_RDY;
}

micSample_t MicrophoneDriver_Sample(uint8_t port) {
    return ADC_Sample();
}