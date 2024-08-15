class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return false;
        int fiveDollar = 0, tenDollar = 0;
        const int PER_LEMONADE_COST = 5;

        for (const int bill : bills) {
            int change = bill - PER_LEMONADE_COST;
            if (change == 0) 
                fiveDollar++;
            else if (change == 5) {
                if (fiveDollar == 0) return false;
                else fiveDollar--;
                tenDollar++;
            } else if (change == 15) {
                if (tenDollar > 0 && fiveDollar > 0) {
                    tenDollar--;
                    fiveDollar--;
                } else if (fiveDollar >= 3) {
                    fiveDollar -= 3;
                } else return false;
            }
        }
        return true;
    }
};