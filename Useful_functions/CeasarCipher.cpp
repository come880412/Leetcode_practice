#include <iostream>
#include <string>
using namespace std;

string CaesarCipher(string str, int num) {
  
  // code goes here  
  if (num == 0) return str;

  for (int i = 0; i < str.length(); ++i) {
    char currWord = str[i];
    if ((currWord >= 32 && currWord <=47) || (currWord >= 91 && currWord <= 96) || (currWord >= 123))
        continue;
    
    if (currWord != ' ') {
      if (97 <= currWord && currWord <= 122) { // capital letter
        if (currWord + num > 122) currWord -= 26; // Out of bound checking
      } else if (65 <= currWord && currWord <= 90){ // little letter
        if (currWord + num > 90) currWord -= 26; // Out of bound checking
      } 
      currWord += num;
      str[i] = currWord;
    }
  }

  return str;
}

int main() {

	// keep this function call here
	cout << CaesarCipher("Hello",4) << endl; // Lipps
	cout << CaesarCipher("abc",0) << endl; // abc
	cout << CaesarCipher("Caesar Cipher",2) << endl; // Ecguct Ekrjgt
	cout << CaesarCipher("dogs", 8) << endl;
	cout << CaesarCipher("byte", 13) << endl;
	return 0;

}