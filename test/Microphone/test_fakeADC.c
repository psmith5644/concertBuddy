#include "unity.h"

/* 
Test List:
- the next sample is -1 if a nextsample has not been set.
- the getnextsample() function returns whatever was the previous value in setnextsample()
- there is an initialize oneshot function that sets the status flag to ready for oneshot samples
- an initialize continuous function sets the status flag to ready for continuous samples
- continuousSamplingBegin() will begin continuous sampling, sending the data to a buffer via DMA
- continuousSamplingStop() will stop the continuous sampling.
*/

void setup(void) {

}

void teardown(void) {

}
