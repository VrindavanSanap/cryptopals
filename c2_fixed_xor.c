#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int hex_to_int(char hex_char)
{
    int value;
    if (hex_char >= '0' && hex_char <= '9')
    {
        value = hex_char - '0';
    }
    else if (hex_char >= 'A' && hex_char <= 'F')
    {
        value = hex_char - 'A' + 10;
    }
    else if (hex_char >= 'a' && hex_char <= 'f')
    {
        value = hex_char - 'a' + 10;
    }
    return value;
}
char *int_to_binary(int n, int n_bits)
{
    char *binary_string = (char *)malloc(n_bits + 1);
    for (int i = n_bits - 1; i >= 0; i--)
    {
        binary_string[n_bits - i - 1] = ((n >> i) & 1) + '0';
    }
    binary_string[n_bits] = '\0';
    return binary_string;
}
char *hex_to_binary(const char *hex_string)
{
    int len = strlen(hex_string);
    int binary_string_len = len * 4 + 1;
    char *binary_string = (char *)malloc(binary_string_len);
    for (int i = 0; i < len; i += 1)
    {
        int n = hex_to_int(hex_string[i]);
        char *nibble = int_to_binary(n, 4);
        strcat(binary_string, nibble);
    }

    binary_string[binary_string_len - 1] = '\0';
    return binary_string;
}
int binary_to_int(const char *binary_string)
{
    int n = strtol(binary_string, NULL, 2);
    return n;
}
char *int_to_hex(int n)
{
    char hex_chars[] = "0123456789abcdef";
    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = hex_chars[n];
    result[1] = '\0';
    return result;
}
char* fixed_xor(char* string1, char* string2){
    int len = strlen(string1) + 1;
    char *result = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        int n1 = hex_to_int(string1[i]);
        int n2 = hex_to_int(string2[i]);
        int n3 = n1 ^ n2;
        char *result_hex_digit = int_to_hex(n3);
        strcat(result, result_hex_digit);
    }
    strcat(result, "\0");
    return result;
}
int main(int argc, char *argv[])
{
    char *string1 = "1c0111001f010100061a024b53535009181c";
    char *string2 = "686974207468652062756c6c277320657965";
    char *xored_string = fixed_xor(string1, string2);
    printf("%s", xored_string);
    return 0;
}