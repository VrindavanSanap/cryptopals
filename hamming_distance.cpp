#include <stdio.h>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;

int hamming_dist_strings1(string s1, string s2){
  int dist = 0; 
  for (int i = 0; i < s1.length(); i ++){
    string byte1 =(bitset<8>(s1[i])).to_string(); 
    string byte2 =(bitset<8>(s2[i])).to_string(); 
    for(int j = 0; j < 8; j++){
      if( byte1[j] != byte2[j]) {
        dist += 1;

      }
    }   
  }
  return dist;
}
int hamming_dist_strings(const std::string& s1, const std::string& s2) {
    /// by chatgpt
    int dist = 0;
    if (s1.length() != s2.length()) {
        return -1; 
    }

    for (size_t i = 0; i < s1.length(); ++i) {
        char charFromText1 = s1[i];
        char charFromText2 = s2[i];

        char xorResult = charFromText1 ^ charFromText2;

        while (xorResult > 0) {
            dist += xorResult & 1;
            xorResult >>= 1;
        }
    }
    return dist;
}

int main(){
  string s1 = "wokka wokka!!!";
  string s2 = "this is a test";
  cout << s1 <<endl;
  cout << s2 <<endl;
  int dist = hamming_dist_strings(s1, s2);
  cout << "Hamming distance: " << dist << endl;
}
