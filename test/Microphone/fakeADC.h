#pragma once

#include "../../include/adc.h"

void FakeADC_Init(void);
void FakeADC_Destroy(void);
sample_t FakeADC_GetNextSample(void);
void FakeADC_SetNextSample(sample_t sample);