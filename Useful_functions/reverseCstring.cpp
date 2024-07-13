/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

char* reverseCString(char *str) {
    if (str) {
       char *start = str;
        char *end = str;
        char tmp;
        
        while (*end) end++; // find end of the string
        end--; // Last char is '\0'
        
        // Swap characters
        while (start < end) {
            tmp = *start;
            *start++ = *end;
            *end-- = tmp;
        } 
    }
    return str;
}

int main()
{
    char dummy[] = "abcde"; // edcba
    // char dummy[] = "abcd"; // dcba
    // char dummy[] = "abc"; // cba
    // char dummy[] = "ab"; // ba
    // char dummy[] = "a"; // a
    char *str = dummy;
    cout << reverseCString(str) << endl;
    
    return 0;
}