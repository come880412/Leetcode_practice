#include <stdio.h>
#include <iostream>
#include <vector>

std::vector<int> RabinKarp(const std::string text, const std::string pattern, const int d, const int q) {
    const int n = text.length();
    const int m = pattern.length();
    int p = 0;
    int t = 0;
    int h = 1;
    
    // Initialize the d^(m-1) mod q
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }
    
    // Initialzie the modular for pattern and text
    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    std::vector<int> positions;
    for (int s = 0; s <= n - m; ++s) {
        // If modular is the same, compare the string.
        if (p == t) {
            if (text.substr(s, s + m) == pattern) {
                positions.push_back(s);
            }
        }
        
        if (s < n - m) {
            t = (d * (t - text[s] * h) + text[s + m]) % q;
            if (t < 0) {
                t += q;
            }
        }
    }
    return positions;
}

int main()
{
    const int d = 256;
    const int q = 101;
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    std::vector<int> result = RabinKarp(text, pattern, d, q);

    std::cout << "Pattern found at positions: ";
    for (int pos : result)
        std::cout << pos << " ";
    std::cout << std::endl;

    return 0;
}