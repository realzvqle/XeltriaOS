#ifndef RNG_H_INCLUDED
#define RNG_H_INCLUDED




#include "superheader.h"




uint32_t KiGenerateRandomValue(uint32_t seed);
uint32_t KiGenerateRandomValueWithinRange(uint32_t seed, uint32_t min, uint32_t max);

#endif