// ===========================================================================
// LowLevel01.cpp
// ===========================================================================

#include <iostream>
#include <bitset>

// ===========================================================================
// function prototypes

void low_level_01_bitwise_and();
void low_level_02_bitwise_or();
void low_level_03_bitwise_xor();
void low_level_04_bitwise_negate();
void low_level_05_left_shift();
void low_level_06_right_shift_unsigned();
void low_level_07_right_shift_signed();

// ===========================================================================

void low_level_01_bitwise_and()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1100'1101;

    unsigned short word = word1 & word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs (word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_02_bitwise_or()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;

    unsigned short word = word1 | word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs(word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_03_bitwise_xor()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;

    unsigned short word = word1 ^ word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs(word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_04_bitwise_negate()
{
    unsigned short word = 0b1011'0011;

    unsigned short wordNegated = ~ word;

    std::bitset<16> bsWord(word);
    std::bitset<16> bsWordNegated(wordNegated);

    std::cout << word << std::endl;
    std::cout << wordNegated << std::endl;

    std::cout << bsWord << std::endl;
    std::cout << bsWordNegated << std::endl;
}

void low_level_05_left_shift()
{
    unsigned char byte = 0b0010'0011;
    std::bitset<8> bs(byte);

    unsigned char byteShifted = byte << 1;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

void low_level_06_right_shift_unsigned ()
{
    unsigned char byte = 0b1010'0011;
    std::bitset<8> bs(byte);

    unsigned char byteShifted = byte >> 1;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

void low_level_07_right_shift_signed()
{
    signed char byte = 0b0010'0011;
    std::bitset<8> bs(byte);

    signed char byteShifted = byte >> 2;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;

    byte = -0b1000'0000;
    bs = byte;

    byteShifted = byte >> 3;
    bsShifted = byteShifted;

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

// ===========================================

void main_low_level_01()
{
    low_level_01_bitwise_and();
    low_level_02_bitwise_or();
    low_level_03_bitwise_xor();
    low_level_04_bitwise_negate();
    low_level_05_left_shift();
    low_level_06_right_shift_unsigned();
    low_level_07_right_shift_signed();
}

// ===========================================================================
// End-of-File
// ===========================================================================
