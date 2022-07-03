class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_dict;
        map<char, int> t_dict;
        
        char s_tmp, t_tmp;
        if(s.size() == t.size()){
            for(int i=0; i<s.size(); ++i){
                s_tmp = s[i];
                t_tmp = t[i];
                
                if(s_dict.find(s_tmp) == s_dict.end()) // Not found
                    s_dict[s_tmp]  = 1;
                
                else
                    s_dict[s_tmp] += 1;
                
                
                if(t_dict.find(t_tmp) == t_dict.end()) // Not found
                    t_dict[t_tmp] = 1;
                
                else
                    t_dict[t_tmp] += 1;
            }
            for ( const auto &[key, value]: s_dict ) {
                if(t_dict.find(key) == t_dict.end())
                    return false;
                else{
                    if(t_dict[key] != value)
                        return false;
                }
                    
            }
            return true;
        }
        
        else
            return false;
        
        return false;
    }
};
