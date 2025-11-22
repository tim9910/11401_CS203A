/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"
static const int BASE = 31;
int charToNum(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';  // 0 ~ 25
    else if (c >= 'a' && c <= 'z')
        return 26 + (c - 'a'); // 26 ~ 51
    else 
        return -1;  // other
}

int myHashInt(int key, int m) {
    int r = 0;
    while (key > 0) {
        r = r * 10 + (key % 10);
        key /= 10;
    }
    return (r * BASE + key) % m;
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for (char c : str) {
        int num = charToNum(c);
        if (num != -1) {
            hash = (hash * BASE + static_cast<unsigned long>(num)) % m;
        }
    }
    return static_cast<int>(hash);
}
