#include <iostream>
#include <string>
using namespace std;

char getReplacement(char a, char b) {
    if ((a == 'a' && b == 'b') || (a == 'b' && b == 'a')) return 'c';
    if ((a == 'a' && b == 'c') || (a == 'c' && b == 'a')) return 'b';
    if ((a == 'b' && b == 'c') || (a == 'c' && b == 'b')) return 'a';
    return 0; // This should never happen
}

string StringReduction(string str) {
  // code goes here  
  bool swap;
  do {
      swap = false;
      for (int i = 0; i < str.length() - 1; ++i) {
          if (str[i] != str[i + 1]) {
              char replacement = getReplacement(str[i], str[i + 1]);
              str.replace(i, 2, &replacement);
              swap = true;
              break; 
          }
      }
  } while (swap);
  return str;
}

int main() {

	// keep this function call here
	cout << StringReduction("abcabc") << endl; // 2
	cout << StringReduction("cccc") << endl; // 4
	cout << StringReduction("cab") << endl; // 2
	cout << StringReduction("bcab") << endl; // 1
	return 0;

}