#include <stdio.h>
#include "numconv1.h"

void run_tests() {
    char output[32];
    int num;

    printf("Testing conversion to integer:\n\n");
    // Test decimal to int conversion
    printf("Testing dec_to_int:\n");
    num = dec_to_int("12345");
    printf("Expected: 12345, Got: %d\n", num);

    // Test binary to int conversion
    printf("Testing bin_to_int:\n");
    num = bin_to_int("1010");
    printf("Expected: 10, Got: %d\n", num);

    // Test hex to int conversion
    printf("Testing hex_to_int:\n");
    num = hex_to_int("1A3");
    printf("Expected: 419, Got: %d\n", num);

    // Test octal to int conversion
    printf("Testing oct_to_int:\n");
    num = oct_to_int("17");
    printf("Expected: 15, Got: %d\n", num);

    printf("\nTesting conversion from integer to decimal:\n\n");
    // Test int to decimal conversion
    printf("Testing int_to_dec:\n");
    int_to_dec(12345, output);
    printf("Expected: 12345, Got: %s\n", output);

    printf("Testing int_to_dec:\n");
    int_to_dec(-12345, output);
    printf("Expected: -12345, Got: %s\n", output);

    printf("\nTesting conversion from integer to binary with padding and grouping:\n\n");
    // Binary conversion with padding and grouping
    // Test binary conversion for small numbers
    int_to_bin(5, output);  // Binary should be "0101"
    printf("Input: 5, Expected: 0101, Got: %s\n", output);

    int_to_bin(10, output); // Binary should be "1010"
    printf("Input: 10, Expected: 1010, Got: %s\n", output);

    int_to_bin(7, output);  // Binary should be "0111" (padded)
    printf("Input: 7, Expected: 0111, Got: %s\n", output);

    // Test binary conversion with grouping for larger numbers
    int_to_bin(255, output);  // Binary should be "1111 1111"
    printf("Input: 255, Expected: 1111 1111, Got: %s\n", output);

    int_to_bin(1023, output);  // Binary should be "0011 1111 1111"
    printf("Input: 1023, Expected: 0011 1111 1111, Got: %s\n", output);

    int_to_bin(4096, output);  // Binary should be "0001 0000 0000 0000"
    printf("Input: 4096, Expected: 0001 0000 0000 0000, Got: %s\n", output);

    // Test hexadecimal conversion
    printf("\nTesting conversion from integer to hexidecimal:\n\n");

    // Test hex conversion for small numbers
    int_to_hex(10, output); // Hex should be "A"
    printf("Input: 10, Expected: A, Got: %s\n", output);

    int_to_hex(15, output); // Hex should be "F"
    printf("Input: 15, Expected: F, Got: %s\n", output);

    // Test hex conversion for larger numbers
    int_to_hex(255, output);  // Hex should be "FF"
    printf("Input: 255, Expected: FF, Got: %s\n", output);

    int_to_hex(4095, output);  // Hex should be "FFF"
    printf("Input: 4095, Expected: FFF, Got: %s\n", output);

    int_to_hex(65535, output);  // Hex should be "FFFF"
    printf("Input: 65535, Expected: FFFF, Got: %s\n", output);

    // Test octal conversion
    printf("\nTesting conversion from integer to octal:\n\n");

    // Test octal conversion for small numbers
    int_to_oct(7, output); // Octal should be "7"
    printf("Input: 7, Expected: 7, Got: %s\n", output);

    int_to_oct(10, output); // Octal should be "12"
    printf("Input: 10, Expected: 12, Got: %s\n", output);

    // Test octal conversion for larger numbers
    int_to_oct(255, output);  // Octal should be "377"
    printf("Input: 255, Expected: 377, Got: %s\n", output);

    int_to_oct(4095, output);  // Octal should be "7777"
    printf("Input: 4095, Expected: 7777, Got: %s\n", output);

    // Test edge case with zero
    printf("\nTesting edge cases with zero:\n\n");

    int_to_dec(0, output); // Decimal for 0 should be "0"
    printf("Input: 0, Expected: 0, Got: %s\n", output);

    int_to_bin(0, output); // Binary for 0 should be "0000"
    printf("Input: 0, Expected: 0000, Got: %s\n", output);

    int_to_hex(0, output); // Hex for 0 should be "0"
    printf("Input: 0, Expected: 0, Got: %s\n", output);

    int_to_oct(0, output); // Octal for 0 should be "0"
    printf("Input: 0, Expected: 0, Got: %s\n", output);
}

int main() {
    printf("Running conversion tests with edge cases...\n");
    run_tests();
    return 0;
}
