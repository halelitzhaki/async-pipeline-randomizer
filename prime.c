#include "prime.h"

int isPrime(unsigned int n) {
    if(n == 2) return TRUE;
    if(n < 2 || n % 2 == 0) return FALSE;
    for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return FALSE;
    return TRUE;
}