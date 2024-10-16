#include "kistdlib.h"




char* KiStrCat(char* destination, const char* source) {
    char* dest = destination;

    while (*dest != '\0') {
        dest++;
    }
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return destination;
}

char* KiItoA(int num, char* str) {
    int i = 0;
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);
    if (isNegative) {
        //str[i++] = '-';
    }

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    str[i] = '\0';

    return str;
}


double KiFabs(double x) {
    return (x < 0) ? -x : x;
}

double KiPow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}


float KiFactorial(int n) {
    float result = 1.0f;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

float KiNormAngle(float x) {
    const float PI = 3.14159265358979323846f;
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    return x;
}

float KiSin(float x) {
    x = KiNormAngle(x);  
    float x3 = x * x * x;
    float x5 = x3 * x * x;
    float x7 = x5 * x * x;

    return x - (x3 / KiFactorial(3)) + (x5 / KiFactorial(5)) - (x7 / KiFactorial(7));
}

float KiCos(float x) {
    x = KiNormAngle(x);  
    float x2 = x * x;
    float x4 = x2 * x * x;
    float x6 = x4 * x * x;

    return 1 - (x2 / KiFactorial(2)) + (x4 / KiFactorial(4)) - (x6 / KiFactorial(6));
}
