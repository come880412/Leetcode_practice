class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        
        vector<int> record={1, 1};
        for (int i=1; i<s.length(); ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') 
                    record.push_back(record[i-1]);
                    
                else
                    record.push_back(0);
            }
            else if (s[i-1] == '1')
                record.push_back(record[i-1] + record[i]);
            else if (s[i-1] == '2' && s[i] <= '6')
                record.push_back(record[i-1] + record[i]);
            
            else
                record.push_back(record[i]);
            // cout<<s[i]<<" "<<record[i] <<endl;
        }
        
        return record[s.length()];
    }
};