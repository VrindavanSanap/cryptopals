#include <iostream>
using namespace std;
string hexToBinaryString(const string &hexString)
{
    string binaryString;
    for (size_t i = 0; i < hexString.length(); i += 2)
    {
        uint8_t byte = stoi(hexString.substr(i, 2), nullptr, 16);
        string byte_string = bitset<8>(byte).to_string();
        binaryString += byte_string;
    }
    return binaryString;
}
string xorBinaryStrings(const string s1, const string s2){
    string result = "";
    for (size_t i = 0; i < s1.length(); i += 2)
    {
        uint8_t b1 = stoi(s1.substr(i, 2), nullptr, 16);
        uint8_t b2 = stoi(s2.substr(i, 2), nullptr, 16);
        result += bitset<8>(b1 ^ b2).to_string();

    }
    return result;
}
string binaryToHex(string binaryString){

    char hexChars[] = "0123456789abcdef";
    string result = "";
    for (size_t i = 0; i < binaryString.length(); i += 4)
    {
        uint8_t index = bitset<8>(binaryString.substr(i, 4)).to_ulong();
        result += hexChars[index];
    }
    return result;
}
string xorHexString(string string1, string string2){
    return binaryToHex(xorBinaryStrings(string1, string2));
}
int main()
{
    const string s1 = "1c0111001f010100061a024b53535009181c";
    const string s2 = "686974207468652062756c6c277320657965";
    cout << xorHexString(s1, s2);
    return 0;
}