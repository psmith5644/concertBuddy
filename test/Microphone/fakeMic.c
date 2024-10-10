#include "fakeMic.h"

void Mic_Init(void) {

}

void Mic_Destroy(void) {

} 

micSample FakeMic_Sample(micSample sample) {
    return sample;
}