#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t    answer = 0;

        for (unsigned int i = 0; i < 32; ++i) {
            answer <<= 1;
            // 10011100 & 0000001 -> 000000000 
            answer = answer | ( n & 1 );
            n >>= 1; 
        }
        return (answer);
    }
};