class Solution {
public:
    int countSubstrings(string s) {
        int countResult = 0, n = s.size();
        
        vector<vector<bool>> res( n , vector<bool> (n, false));
        
        for(int i=n-1 ; i>=0 ; --i){
            for(int j=i ; j<n ; ++j){
                
                if((j - i) <= 2 && s[i] == s[j]){
                    res[i][j] = true;
                    countResult += 1;
                }
                
                else if((j - i) > 2 && s[i] == s[j] && res[i+1][j-1] == true){
                    res[i][j] = true;
                    countResult += 1;
                }
                    
                    
            }
        }
        
        return countResult;
    }
};