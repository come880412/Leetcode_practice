class Solution {
public:
    unordered_map<int, string> d = {
    {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
    {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
    {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
    {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
    {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},    
    {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }

    string helper(int num) {
        string result;

        if (num < 20) 
            result = this->d[num];
        else if (num >= 20 && num < 100)
            result = this->d[num / 10 * 10] + " " + this->d[num % 10];
        else if (num >= 100 && num < 1000) 
            result = this->d[num / 100] + " " + this->d[100] + " " + helper(num % 100);
        else if (num >= 1000 && num < 1000000)
            result = helper(num / 1000) + " " + this->d[1000] + " " + helper(num % 1000);
        else if (num >= 1000000 && num < 1000000000)
            result = helper(num / 1000000) + " " + this->d[1000000] + " " + helper(num % 1000000);
        else
            result = helper(num / 1000000000) + " " + this->d[1000000000] + " " + helper(num % 1000000000);
        if (result.length() && result[result.length() - 1] == ' ')
            result = result.substr(0, result.length() - 1);

        return result;
    }
};