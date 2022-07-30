class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        map<char, int> letter;
        int letterFreq = 0, maxSub = 0;
        
        for(int i = 0 ; i < s.size() ; ++i){
            letter[s[i]]++;
            
            letterFreq = max(letterFreq, letter[s[i]]);
            
            if((i-start+1 - letterFreq) > k){
                letter[s[start]]--;
                start++;
            }
            
            maxSub = max(maxSub, i-start+1);
            
        }
        
        return maxSub;
    }
};