class Solution {
public:
    string fractionAddition(string expression) {
        const int n = expression.length();
        int denominator = 1;
        int numerator = 0;
        int i = 0;
        int sign = 1;

        if (expression[i] == '-') {
            i++;
            sign = -1;
        }

        while (i < n) {
            if (expression[i] == '+') {
                sign = 1;
                ++i;
            } else if (expression[i] == '-') {
                sign = -1;
                ++i;
            }

            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + expression[i] - '0';
                ++i;
            }
            
            ++i; // skip '/'

            int den = 0;
            while (isdigit(expression[i])) {
                den = den * 10 + expression[i] - '0';
                ++i;
            }

            numerator = numerator * den + sign * num * denominator;
            denominator = den * denominator;

            int gcdVal = gcd(numerator, denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};