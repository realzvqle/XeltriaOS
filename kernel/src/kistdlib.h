#ifndef KISTDLIB_H_INCLUDED
#define KISTDLIB_H_INCLUDED






#include "superheader.h"
#include <stdint.h>

typedef struct _version{
    uint8_t osver;
    uint16_t kver;
    char* type;
} version;

char* KiStrCat(char* destination, const char* source);
char* KiItoA(int num, char* str);
double KiFabs(double x);
double KiPow(double base, int exp);
float KiSin(float x);
float KiCos(float x);
void KiSliceStrings(const char* sourcestring, char delimiter, char* firststring, char* secondstring, size_t firstsize, size_t secondsize);
bool KiStringCompare(char* first_string, char* second_string);
version KiGetCurrentVersion();
#endif