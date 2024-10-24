#pragma once

#include <stdint.h>

typedef uint32_t sample_t;

typedef enum {
    ADC_STATUS_ONESHOT_RDY,
    ADC_STATUS_CONTINUOUS_RDY,
    ADC_STATUS_CONTINUOUS_SAMPLING
} ADC_STATUS;

void ADC_Init(void);
void ADC_Destroy(void);
sample_t ADC_Sample(void);
ADC_STATUS ADC_GetStatus(void);
void ADC_InitContinuousSampling(void);
void ADC_ContinuousSamplingBegin(void);
void ADC_ContinuousSamplingStop(void);