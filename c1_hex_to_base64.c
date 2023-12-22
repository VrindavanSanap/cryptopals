#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int hex_to_int(char hex_char)
{
    int value;
    if (hex_char >= '0' && hex_char <= '9'){
        value = hex_char - '0';
    }
    else if (hex_char >= 'A' && hex_char <= 'F'){
        value = hex_char - 'A' + 10;
    }
    else if (hex_char >= 'a' && hex_char <= 'f'){
        value = hex_char - 'a' + 10;
    }
    return value;
}
char* int_to_binary(int n, int n_bits){
    char *binary_string = (char *)malloc(n_bits +1);
    for (int i = n_bits -1; i >= 0; i--){
        binary_string[n_bits - i -1] = ((n >> i) & 1) + '0';
    }
    binary_string[n_bits] = '\0';
    return binary_string;
}
char *hex_to_binary(const char *hex_string)
{
    int len = strlen(hex_string);
    int binary_string_len = len * 4 + 1;
    char *binary_string = (char *)malloc(binary_string_len);
    for (int i =0; i < len; i += 1){
        int n = hex_to_int(hex_string[i]);
        char* nibble = int_to_binary(n, 4);
        strcat(binary_string, nibble);
    }

    binary_string[binary_string_len - 1] = '\0';
    return binary_string;
}
int binary_to_int(const char* binary_string){
    int n = strtol(binary_string, NULL, 2);
    return n;
}
char* int_to_base64(int n){
    char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = base64Chars[n];
    result[1] = '\0';
    return result;
}
char* binary_to_base64(char* binary_string){
    while(strlen(binary_string)%6 != 0){
        strcat(binary_string, "0");
    }

    int base64_string_len = ((strlen(binary_string) / 6));
    base64_string_len += (4 - (base64_string_len% 4)) % 4;
    char *base64_string = (char *)malloc((base64_string_len + 1)* sizeof(char));
    for (int i = 0; i < strlen(binary_string); i += 6)
    {
        char *hex_binary_string= (char *)malloc(6);
        strncpy(hex_binary_string, binary_string + i, 6);
        int base64_int = binary_to_int(hex_binary_string);
        char* base64_char = int_to_base64(base64_int); 
        strcat(base64_string, base64_char); 
     }
    while(strlen(base64_string)%4 != 0){
        strcat(base64_string, "=");
    }

        strcat(base64_string, "\0");
 
    return base64_string;
}
char *hex_to_base64(const char *hex_string){
    char *base64_string = "";
    printf("hex string: %s \n", hex_string);
    char *binary_string = hex_to_binary(hex_string);
    base64_string = binary_to_base64(binary_string);
    printf("base64 string: %s \n", base64_string);
    return base64_string;
}
int main(int argc, char *argv[]){
    if (argc != 2)
    {
        printf("Please provide a single string as a command-line argument.\n");
        return 1;
    }

    char *hex_string= argv[1];
    char *base64_string = hex_to_base64(hex_string);

    return 0;
}