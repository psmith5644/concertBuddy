#pragma once

#include <stdint.h>

typedef uint32_t sample_t;

typedef enum {
    ADC_STATUS_ONESHOT_RDY
} ADC_STATUS;

void ADC_Init(void);
void ADC_Destroy(void);
sample_t ADC_Sample(void);
ADC_STATUS ADC_GetStatus(void);
