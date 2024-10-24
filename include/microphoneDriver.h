#pragma once

#include <stdint.h>

typedef enum {
    MIC_STATUS_RDY
} MIC_STATUS;

typedef uint32_t micSample_t;

void MicrophoneDriver_Init(uint8_t port);
void MicrophoneDriver_Destroy(uint8_t port);
MIC_STATUS MicrophoneDriver_GetStatus(uint8_t port);
micSample_t MicrophoneDriver_Sample(uint8_t port);
