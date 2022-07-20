class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> anagram;
        
        string tmp_str;
        for(int i=0 ; i<strs.size() ; ++i){
            tmp_str = strs[i];
            sort(tmp_str.begin(),tmp_str.end());
            
            anagram[tmp_str].push_back(strs[i]);
            // cout<<anagram[tmp_str]<<" ";
        }
        
        for (const auto& s : anagram) {
            result.push_back(s.second);
        }
        
        return result;
    }
};