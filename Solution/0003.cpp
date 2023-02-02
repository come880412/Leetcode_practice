class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charDict;
        
        int maxLen = 0, start=0, end=0;
        for(int i=0 ; i < s.size() ; ++i){
            if(charDict.find(s[i]) != charDict.end()){
                end = charDict[s[i]];
                for(int j=start; j<=end; ++j){
                    charDict.erase(s[j]);
                }
                start = end + 1;
            }
            charDict[s[i]] = i;
            
            if(charDict.size() > maxLen) maxLen = charDict.size();
        }
        
        return maxLen;
    }
};