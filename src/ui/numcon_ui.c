#include <stdio.h>
#include "numcon.h"
#include "numcon_ui.h"

void print_menu() {
    printf("Select the input number system:\n");
    printf("1: Decimal\n");
    printf("2: Binary\n");
    printf("3: Hexadecimal\n");
    printf("4: Octal\n");
}

int main() {
    // Declare variables to store the input and output numbers
    char input[32];
    char output[32];

    // Declare variables to store the choice and the number
    int choice;
    int number;

    // Read the choice from the user as an integer
    print_menu();
    scanf("%d", &choice); 
    
    // Read the number from the user as a string
    printf("Enter the number: ");
    scanf("%s", input); 

    // Convert the input number to an integer based on the choice
    switch (choice) {
        case 1:
            number = dec_to_int(input);
            break;
        case 2:
            number = bin_to_int(input);
            break;
        case 3:
            number = hex_to_int(input);
            break;
        case 4:
            number = oct_to_int(input);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    // Read the output choice from the user as an integer
    printf("Select the output number system:\n");
    printf("1: Decimal\n");
    printf("2: Binary\n");
    printf("3: Hexadecimal\n");
    printf("4: Octal\n");
    scanf("%d", &choice);

    // Convert the number to the output number system
    switch (choice) {
        case 1:
            int_to_dec(number, output);
            break;
        case 2:
            int_to_bin(number, output);
            break;
        case 3:
            int_to_hex(number, output);
            break;
        case 4:
            int_to_oct(number, output);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    // Print the output number as a string
    printf("Output: %s\n", output); 
    return 0;
}
