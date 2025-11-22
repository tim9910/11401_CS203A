/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation (Yu-Feng Huang)
    - 2025/11/17: Refactored to use hash_fn.hpp (Yu-Feng Huang)
    - 2025/11/23: Implemented custom integer and string hash functions (林晉霆)

   Developer(s):
    - Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
    - 林晉霆 <s1133322@mail.yzu.edu.tw>      
 */
#include "hash_fn.hpp"
static const int BASE = 31;

/**
 * @brief Convert character to numerical value       
 * @param c The character to convert.
 * @return The numerical value of the character.
 *         'A'-'Z' 0-25, 'a'-'z' 26-51, others -1
 */
int charToNum(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';  // 0 ~ 25
    else if (c >= 'a' && c <= 'z')
        return 26 + (c - 'a'); // 26 ~ 51
    else 
        return -1;  // other
}

/**
 * @brief Computes the hash index for an integer key.
 * @param key The integer key to hash.
 * @param m The table size.
 * @return The computed hash index.
 */
int myHashInt(int key, int m) {
    int r = 0;
    int original = key; //保留原始值

    // 反轉整數位數
    while (key > 0) {
        r = r * 10 + (key % 10);
        key /= 10;
    }

    return (r * BASE + original) % m;
}

/**
 * @brief Computes the hash index for a string key.
 * @param str The string key to hash.
 * @param m The table size.
 * @return The computed hash index.
 */
int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    for (char c : str) {
        int num = charToNum(c);
        if (num != -1) {
            hash = (hash * BASE + static_cast<unsigned long>(num)) % m;
        }
    }
    return static_cast<int>(hash);
}
