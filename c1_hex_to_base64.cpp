#include <iostream>
#include <bitset>
#include <string>
using namespace std;
string hexToBase64(const std::string &hexString){
    char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string binaryString;

    for (size_t i = 0; i < hexString.length(); i += 2){
        uint8_t byte = stoi(hexString.substr(i, 2), nullptr, 16);
        string byte_string = bitset<8>(byte).to_string();
        binaryString += byte_string;


    }

    while (binaryString.length() % 6 != 0){
        binaryString += "00";
    }
    cout << "binary string: " << binaryString<< std::endl;
    string base64String;
    for (size_t i = 0; i < binaryString.length(); i += 6){
        uint8_t index = bitset<6>(binaryString.substr(i, 6)).to_ulong();
        base64String += base64Chars[index];
    }
    while (base64String.length() % 4 != 0){
        base64String += '=';
    }
    return base64String;
}

int main()
{
    string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"; 
        string base64String = hexToBase64(hexString);

    cout << "Hexadecimal string: " << hexString << std::endl;
    cout << "Base64 string: " << base64String << std::endl;

    return 0;
}
