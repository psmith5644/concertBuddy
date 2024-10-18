#pragma once

#include <stdint.h>
#include "microphoneDriver.h"

void MicrophoneController_Init(void);
void MicrophoneController_Destroy(void);
uint32_t MicrophoneController_Sample(void);