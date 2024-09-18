#include <stdio.h>
#include "numconv1.h"

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
    int current = 0; // The current character in the string

    // iterate over the string and convert the number to an integer with an while loop
    while (str[current] != '\0') {
        // Check if the number is a valid digit
        if (!is_bin_digit(str[current])) {
            return 0; // Return 0 if the number is not a valid digit
            // TODO figure out how to handle invalid input
        }
        // Convert the character to an integer and add it to the result
        // Multiply the result by 2 to shift the bits to the left
        result *= 2;
        // Add the binary digit to the result
        int bin_digit = str[current] - '0';
        result += bin_digit;
        // Move to the next character in the string
        current++;
    }
    // return the result
    return result;
}

// Conversion functions from hexadecimal to integer
int hex_to_int(char str[]) {
    int result = 0;
    int current = 0; // The current character in the string

    // iterate over the string and convert the number to an integer with an while loop
    while (str[current] != '\0') {
        // Check if the number is a valid digit
        if (!is_hex_digit(str[current])) {
            return 0; // Return 0 if the number is not a valid digit
            // TODO figure out how to handle invalid input
        }
        // Convert the character to an integer and add it to the result
        // Multiply the result by 16 to shift the bits to the left
        result *= 16;
        // Add the hexadecimal digit to the result
        int hex_digit = str[current] - '0'; // Convert the character to an integer by subtracting the ASCII value of '0' e.g '5' - '0' = 5 because '5' is 53 and '0' is 48
        if (hex_digit > 9) {
            // handle uppercase letters
            if (str[current] >= 'A' && str[current] <= 'F') {
                hex_digit = str[current] - 'A' + 10; // Convert the character to an integer by subtracting the ASCII value of 'A' and adding 10 e.g 'D' - 'A' + 10 = 13 because 'D' is 68 and 'A' is 65
            } else {
                // handle lowercase letters
                hex_digit = str[current] - 'a' + 10; // Convert the character to an integer by subtracting the ASCII value of 'a' and adding 10 e.g 'd' - 'a' + 10 = 13 because 'd' is 100 and 'a' is 97
            }
        }
        // add the hexadecimal digit to the result
        result += hex_digit;
        // Move to the next character in the string
        current++;
    }
    // return the result
    return result;
}

// Conversion functions from octal to integer
int oct_to_int(char str[]) {
    int result = 0;
    int current = 0; // The current character in the string

    // iterate over the string and convert the number to an integer with an while loop
    while (str[current] != '\0') {
        // Check if the number is a valid digit
        if (!is_oct_digit(str[current])) {
            return 0; // Return 0 if the number is not a valid digit
            // TODO figure out how to handle invalid input
        }
        // Convert the character to an integer and add it to the result
        // Multiply the result by 8 to shift the bits to the left
        result *= 8;
        // Add the octal digit to the result
        int oct_digit = str[current] - '0';
        result += oct_digit;
        // Move to the next character in the string
        current++;
    }
    // return the result
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
    int position = 0; // The current position in the string
    int remain = num; // The remaining number to convert
    int group_counter = 0; // The number of bits in a group of 4

    do {
        if (group_counter == 4) {
            // Add a space every 4 bits
            str[position++] = ' ';
            group_counter = 0; // Reset the group counter
        }

        // Convert the last digit of the number to a character and add it to the string
        int digit = '0' + remain % 2;
        str[position++] = digit;
        // Divide the number by 2 to remove the last digit
        remain /= 2;
        group_counter++;
    } while (remain > 0);

    // Add padding so the final group has 4 bits
    while (group_counter < 4) {
        str[position++] = '0';
        group_counter++;
    }

    // Add a null terminator to the end of the string
    str[position] = '\0';
    // Reverse the string to get the correct order of the bits
    reverse(str);
}

// Conversion functions from integer to hexadecimal
void int_to_hex(int num, char str[]) {
    const char hex_digits[] = "0123456789ABCDEF";
    int position = 0; // The current position in the string
    int remain = num; // The remaining number to convert

    do {
        // Convert the last digit of the number to a character and add it to the string
        int digit = hex_digits[remain % 16];
        str[position++] = digit;
        // Divide the number by 16 to remove the last digit
        remain /= 16;
    } while (remain > 0);

    // Add a null terminator to the end of the string
    str[position] = '\0';

    // Reverse the string to get the correct order of the digits
    reverse(str);
}

// Conversion functions from integer to octal
void int_to_oct(int num, char str[]) {
    int position = 0; // The current position in the string
    int remain = num; // The remaining number to convert

    do {
        // Convert the last digit of the number to a character and add it to the string
        int digit = '0' + remain % 8;
        str[position++] = digit;
        // Divide the number by 8 to remove the last digit
        remain /= 8;
    } while (remain > 0);
    // Add a null terminator to the end of the string
    str[position] = '\0';
    // Reverse the string to get the correct order of the digits
    reverse(str);
}
