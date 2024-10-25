#pragma once

#include "../../include/adc.h"

void FakeADC_SetNextSample(sample_t sample);
void FakeADC_SetBuffer(sample_t * buf, size_t size);