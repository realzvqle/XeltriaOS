#include "runtimelib.h"




char* RtlStringConcatnate(char* destination, const char* source) {
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

char* RtlIntegerToAscii(int num, char* str) {
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


double RtlFabs(double x) {
    return (x < 0) ? -x : x;
}

double RtlPow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}


float RtlFactorial(int n) {
    float result = 1.0f;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

float RtlNormAngle(float x) {
    const float PI = 3.14159265358979323846f;
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    return x;
}

float RtlSin(float x) {
    x = RtlNormAngle(x);  
    float x3 = x * x * x;
    float x5 = x3 * x * x;
    float x7 = x5 * x * x;

    return x - (x3 / RtlFactorial(3)) + (x5 / RtlFactorial(5)) - (x7 / RtlFactorial(7));
}

float RtlCos(float x) {
    x = RtlNormAngle(x);  
    float x2 = x * x;
    float x4 = x2 * x * x;
    float x6 = x4 * x * x;

    return 1 - (x2 / RtlFactorial(2)) + (x4 / RtlFactorial(4)) - (x6 / RtlFactorial(6));
}

void RtlSliceStrings(const char* sourcestring, char delimiter, char* firststring, char* secondstring, size_t firstsize, size_t secondsize) {
    size_t i = 0;

    while (sourcestring[i] != '\0' && sourcestring[i] != delimiter && i < firstsize - 1) {
        firststring[i] = sourcestring[i];
        i++;
    }
    
    firststring[i] = '\0';

    if (sourcestring[i] == delimiter) {
        i++; 
    }

    size_t j = 0;
    while (sourcestring[i] != '\0' && j < secondsize - 1) {
        secondstring[j] = sourcestring[i];
        i++;
        j++;
    }
    
    secondstring[j] = '\0';
}

bool RtlStringCompare(char* first_string, char* second_string) {
    int index = 0;
    
    while (true) {
        if (first_string[index] != second_string[index]) {
            return false;
        }

        if (first_string[index] == '\0' && second_string[index] == '\0') {
            return true;
        }

        index++;
    }
}


version RtlGetCurrentVersion(){
    version ver;
    ver.kver = 0;
    ver.osver = 0;
    ver.type = "IN DEVELOPMENT";
    return ver;
}

int RtlAsciiToInteger(const char *str) {
    int sign = 1;
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        int digit = str[i] - '0';

        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}