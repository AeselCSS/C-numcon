#include <stdio.h>
#include "numcon.h"

// Helper functions to check if a number is valid
// Check if a character is a digit (0-9)
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Check if a character is a binary digit (0 or 1)
int is_bin_digit(char c) {
    return c == '0' || c == '1';
}
// Check if a character is a hexadecimal digit (0-9, A-F, a-f)
int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

// Check if a character is an octal digit (0-7)
int is_oct_digit(char c) {
    return c >= '0' && c <= '7';
}

// Reverse a string
void reverse(char str[]) {
    int length = 0;
    // Find the length of the string
    while (str[length] != '\0') {
        length++;
    }
    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        // temp variable to store the character at position i
        char temp = str[i];
        // set str[i] to the character at position length - i - 1 which is the character at the opposite end of the string (length - 1 is the last character, length - 2 is the second to last character, etc.)
        str[i] = str[length - i - 1];
        // set the character at position length - i - 1 to the temp variable which is the character at position i
        str[length - i - 1] = temp;
    }
}

// Conversion functions from decimal to integer
int dec_to_int(char str[]) {
    int result = 0;
    int sign = 1; // 1 for positive, -1 for negative
    int current = 0; // The current character in the string

    // Check if the number is negative
    if (str[0] == '-') {
        sign = -1;
        current++;
    }

    // iterate over the string and convert the number to an integer with an while loop
    while (str[current] != '\0') {
        // Check if the number is a valid digit
        if (!is_digit(str[current])) {
            return 0; // Return 0 if the number is not a valid digit
            // TODO figure out how to handle invalid input
        }
        // Convert the character to an integer and add it to the result
        result = result * 10 + (str[current] - '0');
        current++;
    }
    // return the result
    return result * sign;
}

// Conversion functions from binary to integer
int bin_to_int(char str[]) {
    int result = 0;
    int current = 0;

    while (str[current] != '\0') {
        if (!is_bin_digit(str[current])) {
            return 0;  // Invalid input
        }
        result = (result << 1) | (str[current] - '0');
        current++;
    }

    return result;
}

// Conversion functions from hexadecimal to integer
int hex_to_int(char str[]) {
    int result = 0;
    int current = 0;

    while (str[current] != '\0') {
        if (!is_hex_digit(str[current])) {
            return 0;  // Invalid input
        }
        result <<= 4;  // Shift left by 4 (equivalent to multiplying by 16)
        
        if (str[current] >= '0' && str[current] <= '9') {
            result |= (str[current] - '0');
        } else if (str[current] >= 'A' && str[current] <= 'F') {
            result |= (str[current] - 'A' + 10);
        } else if (str[current] >= 'a' && str[current] <= 'f') {
            result |= (str[current] - 'a' + 10);
        }
        
        current++;
    }

    return result;
}


// Conversion functions from octal to integer
int oct_to_int(char str[]) {
    int result = 0;
    int current = 0;

    while (str[current] != '\0') {
        if (!is_oct_digit(str[current])) {
            return 0;  // Invalid input
        }
        result <<= 3;  // Shift left by 3 (equivalent to multiplying by 8)
        result |= (str[current] - '0');
        current++;
    }

    return result;
}


// Conversion functions from integer to decimal
void int_to_dec(int num, char str[]) {
    int position = 0; // The current position in the string
    int remain = num; // The remaining number to convert

    // Handle negative numbers
    if (num < 0) {
        str[position++] = '-';
        remain = -remain;
    }

    do {
        // Convert the last digit of the number to a character and add it to the string
        int digit = '0' + remain % 10;
        str[position++] = digit;
        // Divide the number by 10 to remove the last digit
        remain /= 10;
    } while (remain > 0);
    // Add a null terminator to the end of the string
    str[position] = '\0';

    // Reverse the string to get the correct order of the digits taking into account the negative sign
    if (str[0] == '-') {
        reverse(str + 1); // Reverse after the negative sign
    } else {
        reverse(str);
    }
}

// Conversion functions from integer to binary
void int_to_bin(int num, char str[]) {
    int position = 0;
    int group_counter = 0;

    do {
        if (group_counter == 4) {
            str[position++] = ' ';
            group_counter = 0;
        }
        str[position++] = (num & 1) ? '1' : '0';
        num >>= 1;
        group_counter++;
    } while (num > 0);

    // Add padding to the last group if necessary
    while (group_counter < 4) {
        str[position++] = '0';
        group_counter++;
    }

    str[position] = '\0';
    reverse(str);
}


// Conversion functions from integer to hexadecimal
void int_to_hex(int num, char str[]) {
    const char hex_digits[] = "0123456789ABCDEF";
    int position = 0;

    do {
        str[position++] = hex_digits[num & 0xF];  // Mask with 0xF (equivalent to %16)
        num >>= 4;  // Shift right by 4 (equivalent to dividing by 16)
    } while (num > 0);

    str[position] = '\0';
    reverse(str);
}


// Conversion functions from integer to octal
void int_to_oct(int num, char str[]) {
    int position = 0;

    do {
        str[position++] = (num & 0x7) + '0';  // Mask with 0x7 (equivalent to %8)
        num >>= 3;  // Shift right by 3 (equivalent to dividing by 8)
    } while (num > 0);

    str[position] = '\0';
    reverse(str);
}

