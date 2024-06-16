#define COMPLETE_DAY 24

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        
        unordered_map<int, int> map;
        
        long long int result = 0;
        for (int i = n - 1; i >= 0; --i) {
            int hour = hours[i] % COMPLETE_DAY;
            int matchedHour = (COMPLETE_DAY - hour) % COMPLETE_DAY;
            result += map[matchedHour];
            map[hour] += 1;
        }
        return result;
    }
};