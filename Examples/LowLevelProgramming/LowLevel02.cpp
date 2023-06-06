// ===========================================================================
// LowLevel02.cpp
// ===========================================================================

#include <iostream>
#include <iomanip>
#include <bitset>

// ===========================================================================

// function prototypes
void setBit(unsigned int value, int pos);
void setBit(unsigned int* value, int pos);
void clearBit(unsigned int* value, int pos);
void clearBit(unsigned int value, int pos);

bool isBitSet(unsigned int value, int pos);
bool isBitCleared(unsigned int value, int pos);

int countOnes(unsigned int value);
int countZeros(unsigned int value);
int countOnesEx(unsigned int value);
int countZerosEx(unsigned int value);

void powerOfTwo();
void printIntAsBinary(unsigned int value);

unsigned int encodeColor(unsigned char red, unsigned char green, unsigned char blue);
void decodeColor(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue);
void decodeColorEx(unsigned int color, unsigned char* red, unsigned char* green, unsigned char* blue);

void low_level_01_set_clear_bit();
void low_level_02_count_ones_and_zeros();
void low_level_03_count_ones_and_zeros_ex();
void low_level_04_print_binary();
void low_level_05_testPowerOfTwo();
void low_level_06_testSignedVsUnsignedShift();
void low_level_07_encodeColor();
void low_level_07_decodeColor();

// ===========================================================================

void setBit(unsigned int value, int pos)
{
    unsigned int mask = 1 << pos;

    value = value | mask;
}

void clearBit(unsigned int value, int pos)
{
    unsigned int mask = ~(1 << pos);

    value = value & mask;
}

void setBit(unsigned int* value, int pos)
{
    unsigned int mask = 1 << pos;

    *value = *value | mask;
}

void clearBit(unsigned int* value, int pos)
{
    unsigned int mask = ~(1 << pos);

    *value = *value & mask;
}

bool isBitSet(unsigned int value, int pos)
{
    unsigned int mask = 1;

    mask = mask << pos;

    unsigned int tmp = value & mask;

    return (tmp != 0) ? true : false;
}

bool isBitCleared(unsigned int value, int pos)
{
    unsigned int mask = 1;

    mask = mask << pos;

    unsigned int tmp = value & mask;

    return (tmp == 0) ? true : false;
}

void low_level_01_set_clear_bit()
{
    unsigned int s = 0b1011'0011;

    std::bitset<8> bsBefore(s);
    std::cout << bsBefore << std::endl;

    setBit(&s, 3);

    std::bitset<8> bsAfter(s);
    std::cout << bsAfter << std::endl;

    clearBit(&s, 4);

    bsAfter = s;
    std::cout << bsAfter << std::endl;
}

// ===========================================================================

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

void low_level_02_count_ones_and_zeros()
{
    int value = 7;

    std::bitset<32> bs(value);
    std::cout << bs << std::endl;
    int count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    bs = value;
    std::cout << bs << std::endl;
    count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    bs = value;
    std::cout << bs << std::endl;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    bs = value;
    std::cout << bs << std::endl;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    bs = value;
    std::cout << bs << std::endl;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

void low_level_03_count_ones_and_zeros_ex()
{
    int value = 7;

    std::bitset<32> bs(value);
    std::cout << bs << std::endl;
    int count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    bs = value;
    std::cout << bs << std::endl;
    count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    bs = value;
    std::cout << bs << std::endl;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    bs = value;
    std::cout << bs << std::endl;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    bs = value;
    std::cout << bs << std::endl;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

// ===========================================================================

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

// ===========================================================================

void powerOfTwo()
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1;

    int index = 0;

    do
    {
        ++index;
        std::cout << std::setw(2) << std::setfill(' ') << index << ": " << mask << std::endl;

        mask = mask << 1;

        --numBits;

    } while (numBits != 0);
}

void low_level_05_testPowerOfTwo()
{
    powerOfTwo();
}

// ===========================================================================

unsigned int encodeColor(unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned int redChannel = red;
    unsigned int greenChannel = green;
    unsigned int blueChannel = blue;

    redChannel = redChannel << 16;
    greenChannel = greenChannel << 8;

    unsigned int result = redChannel | greenChannel | blueChannel;
    return result;
}

void decodeColor(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue)
{
    red = (color & 0x00FF0000) >> 16;
    green = (color & 0x0000FF00) >> 8;
    blue = (color & 0x000000FF) >> 0;
}

// or

void decodeColorEx(unsigned int color, unsigned char* red, unsigned char* green, unsigned char* blue)
{
    *red = (color & 0x00FF0000) >> 16;
    *green = (color & 0x0000FF00) >> 8;
    *blue = (color & 0x000000FF) >> 0;
}

void low_level_07_encodeColor()
{
    // 255 - 0 - 255: Magenta
    unsigned int magenta = encodeColor(255, 0, 255);
    std::bitset<32> bsMagenta(magenta);
    std::cout << bsMagenta << std::endl;

    // 255 - 102 - 102: very red light
    unsigned int veryRedLight = encodeColor(255, 102, 102);
    std::bitset<32> bsVeryRedLight(veryRedLight);
    std::cout << bsVeryRedLight << std::endl;
}

void low_level_07_decodeColor()
{
    // light green:  0 - 255 - 51
    unsigned int lightGreen = encodeColor(0, 255, 51);

    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;

    decodeColorEx(lightGreen, &red, &green, &blue);

    std::bitset<8> bsRed(red);
    std::bitset<8> bsGreen(green);
    std::bitset<8> bsBlue(blue);

    std::cout << "LightGreen:" << std::endl;
    std::cout << bsRed << std::endl;
    std::cout << bsGreen << std::endl;
    std::cout << bsBlue << std::endl;
}

// ===========================================================================

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

// ===========================================================================

void main_low_level_02()
{
    low_level_01_set_clear_bit();
    std::cout << std::endl;
    low_level_02_count_ones_and_zeros();
    std::cout << std::endl;
    low_level_03_count_ones_and_zeros_ex();
    std::cout << std::endl;
    low_level_04_print_binary();
    std::cout << std::endl;
    low_level_05_testPowerOfTwo();
    std::cout << std::endl;
    low_level_06_testSignedVsUnsignedShift();
    std::cout << std::endl;
    low_level_07_encodeColor();
    std::cout << std::endl;
    low_level_07_decodeColor();
}

// ===========================================================================
// End-of-File
// ===========================================================================
