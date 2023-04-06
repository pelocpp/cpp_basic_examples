// ===========================================================================
// LowLevel02.cpp
// ===========================================================================

#include <iostream>
#include <algorithm>
#include <vector>

#include <bitset>

// ===================================================

// function prototypes
void setBit(unsigned int value, int position);
void setBit(unsigned int* value, int position);
void clearBit(unsigned int* value, int position);
void clearBit(unsigned int value, int position);

bool isBitSet(unsigned int value, int position);
bool isBitCleared(unsigned int value, int position);

int countOnes(unsigned int value);
int countZeros(unsigned int value);

void powerOfTwo();
void printIntAsBinary(unsigned int value);

void low_level_01_set_clear_bit();
void low_level_02_set_clear_bit();
void low_level_03_count_ones_and_zeros();
void low_level_04_print_binary();
void low_level_05_testPowerOfTwo();
void low_level_06_testSignedVsUnsignedShift();

// ===================================================

void setBit(unsigned int value, int position)
{
    unsigned int mask = 1 << position;

    value = value | mask;
}

void clearBit(unsigned int value, int position)
{
    unsigned int mask = ~(1 << position);

    value = value & mask;
}

void setBit(unsigned int* value, int position)
{
    unsigned int mask = 1 << position;

    *value = *value | mask;
}

void clearBit(unsigned int* value, int position)
{
    unsigned int mask = ~(1 << position);

    *value = *value & mask;
}

bool isBitSet(unsigned int value, int position)
{
    unsigned int mask = 1;

    mask = mask << position;

    unsigned int tmp = value & mask;

    return (tmp != 0) ? true : false;
}

bool isBitCleared(unsigned int value, int position)
{
    unsigned int mask = 1;

    mask = mask << position;

    unsigned int tmp = value & mask;

    return (tmp == 0) ? true : false;
}

void low_level_01_set_clear_bit()
{
    unsigned int s = 0b1011'0011;

    std::bitset<16> bsBefore(s);
    std::cout << bsBefore << std::endl;

    setBit(&s, 3);

    std::bitset<16> bsAfter(s);
    std::cout << bsAfter << std::endl;

    clearBit(&s, 4);

    //bsAfter = 


    //// test setBit
    //int number = 33;
    //std::cout << number << std::endl;
    //setBit(&number, 4);
    //std::cout << number << std::endl;

    //// test clearBit
    //number = 33;
    //clearBit(&number, 4);
    //std::cout << number << std::endl;
}

void low_level_02_set_clear_bit()
{
    setBit(33, 4);
    clearBit(49, 4);
}

// ===================================================

int countOnes(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp != 0) {
            result++;
        }

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

int countOnesEx(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitSet(value, pos)) {
            ++result;
        }
    }

    return result;
}

int countZeros(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp == 0) {
            result++;
        }

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

int countZerosEx(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitCleared(value, pos)) {
            ++result;
        }
    }

    return result;
}

void low_level_03_count_ones_and_zeros()
{
    int value = 7;
    int count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

void low_level_03_count_ones_and_zeros_ex()
{
    int value = 7;
    int count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

// ===================================================

void printIntAsBinary(unsigned int value)
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1 << (numBits - 1);

    for (int i = 0; i < numBits; ++i)
    {
        int bit = 0;
        
        if ((value & mask) != 0) {
            bit = 1;
        }

        std::cout << bit;

        // print blank after every 4th digit
        if ((i+1) % 4 == 0) {
            std::cout << ' ';
        }

        // shift mask 1 position to the right
        mask = mask >> 1;
    }
}

void low_level_04_print_binary()
{
    printIntAsBinary(7);
    std::cout << std::endl;

    printIntAsBinary(-1);
    std::cout << std::endl;

    printIntAsBinary(2'147'483'647);
    std::cout << std::endl;
}

// ===================================================

void powerOfTwo()
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1;

    do
    {
        std::cout << mask << std::endl;

        mask = mask << 1;

        --numBits;

    } while (numBits != 0);
}

void low_level_05_testPowerOfTwo()
{
    powerOfTwo();
}

// ===================================================

void low_level_06_testSignedVsUnsignedShift()
{
    // create initial mask: 1 in leftmost position
    // note: study output of this program using 'int' vs 'unsigned int' mask
    unsigned int mask = 1 << 31;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;
}

// ===================================================

void main_low_level_02()
{
    //low_level_01_set_clear_bit();
    //low_level_02_set_clear_bit();
    //low_level_03_count_ones_and_zeros();
   low_level_04_print_binary();
    //low_level_05_testPowerOfTwo();
    //low_level_06_testSignedVsUnsignedShift();

    //low_level_03_count_ones_and_zeros();
    //std::cout << std::endl;
    //low_level_03_count_ones_and_zeros_ex();
}

// ===================================================

// ===========================================================================
// End-of-File
// ===========================================================================
