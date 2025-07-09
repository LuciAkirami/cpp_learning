#include <iostream>
#include <cstdint>
using namespace std;

/**
 * Types of Integers
 *
 * short int
 * int
 * long int
 * long long int
 *
 * ----- Non Negative Integers ------
 *
 * unsigned short int
 * unsigned int
 * unsigned long int
 * unsigned long long int
 *
 * -> 1 byte is 8 bits
 */

int main()
{
    // output of sizeof is long unsigned int, for this
    // we use %ld instead %d

    // size of gives the size in bytes
    printf("Size of short int is %ld bits\n", sizeof(short int) * 8);

    // below also works, we can use just "short" instead "short"
    // printf("Size of long int is %ld bits\n", sizeof(short) * 8);

    printf("Size of int is %ld bits\n", sizeof(int) * 8);
    printf("Size of long int is %ld bits\n", sizeof(long int) * 8);

    // below also works, we can use just "long" instead "long int"
    // printf("Size of long int is %ld bits\n", sizeof(long) * 8);

    // this will be same as the long int, it might change on windows
    printf("Size of long long int is %ld bits\n\n", sizeof(long long int) * 8);

    // below also works, we can use just "long long" instead "long long int"
    // printf("Size of long int is %ld bits\n", sizeof(long long) * 8);

    // shortest is char which is 8 bits or 1 byte
    printf("Size of char is %ld bits\n\n", sizeof(char) * 8);

    // ---------- Issues and Solution -----------
    // so we see that long and long long has same size. And also based on the
    // platform we are using, these sizes might change. so in these cases
    // when we are developing something, we want uniformity, i.e. we want
    // the sizes to be same independent of platform

    // for this, c++ gives a library called <cstdin>
    printf("Size of int16_t is %ld bits\n\n", sizeof(int16_t) * 8);
    // this int16_t will be 16 bits in wherever we run, be it mac/windows/linux any

    // similarly we have int8_t, int32_t etc & even unsigned versions like uint8_t etc

    // ---------- Use Binary or HexaDecimal in Integer ----------
    int num = 22;
    int num_hexa = 0x16;   // we can use hexadecimal instead of directly using integer
    int num_bin = 0b10110; // we can also pass binary directly

    printf("Integer value declared directly with Integer: %d\n", num);
    printf("Integer value declared with HexaDecimal: %d\n", num_hexa);
    printf("Integer value declared with Binary: %d\n", num_bin);
}