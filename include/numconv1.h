#ifndef NUMCONV1_H
#define NUMCONV1_H

int is_digit(char c);
int is_bin_digit(char c);
int is_hex_digit(char c);
int is_oct_digit(char c);

int dec_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);
int oct_to_int(char str[]);

void int_to_dec(int num, char str[]);
void int_to_bin(int num, char str[]);
void int_to_hex(int num, char str[]);
void int_to_oct(int num, char str[]);

#endif // NUMCONV1_H
