#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

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
string xorBinaryStrings(const string s1, const string s2)
{
    string result = "";
    for (size_t i = 0; i < s1.length(); i += 2)
    {
        uint8_t b1 = stoi(s1.substr(i, 2), nullptr, 16);
        uint8_t b2 = stoi(s2.substr(i, 2), nullptr, 16);
        result += bitset<8>(b1 ^ b2).to_string();
    }
    return result;
}
string binaryToHex(string binaryString)
{

    char hexChars[] = "0123456789abcdef";
    string result = "";
    for (size_t i = 0; i < binaryString.length(); i += 4)
    {
        uint8_t index = bitset<8>(binaryString.substr(i, 4)).to_ulong();
        result += hexChars[index];
    }
    return result;
}
string xorHexStrings(string string1, string string2)
{
    return binaryToHex(xorBinaryStrings(string1, string2));
}
string charToHexString(char character)
{
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << static_cast<int>(character);
    return ss.str();
}
string repeatString(string givenString, int n)
{
    string result = "";
    for (int i = 0; i < n; i++)
    {
        result += givenString;
    }
    return result;
}
string HexStringToString(const std::string &hexString)
{
    string result;
    for (size_t i = 0; i < hexString.length(); i += 2)
    {
        string byteString = hexString.substr(i, 2);
        char byte = static_cast<char>(std::stoi(byteString, nullptr, 16));
        result += byte;
    }
    return result;
}

int main()
{
    const string s1 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    for (int i = 0; i < 26 * 2; i++)
    {
        string alphabets = "abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string charHex = charToHexString(alphabets[i]);
        string key = repeatString(charHex, s1.length() / 2);
        string res = xorHexStrings(s1, key);
        res = HexStringToString(res);
        cout << alphabets[i] << " --> " << res << endl;
    }
    return 0;
}