class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> record_t, record_s;
        int unique_required = 0; // unique key in string t
        for(int i=0; i < t.size(); ++i){
            if(record_t.find(t[i]) == record_t.end()){
                record_t[t[i]] = 1;
                unique_required += 1;
            }
            else
                record_t[t[i]] += 1;
        }

        int l = 0, count = 0; // sliding window count
        int ans_length = INT_MAX, ans_left = 0, ans_right = 0;
        char character;
        for(int r=0; r < s.size(); ++r){
            character = s[r];
            if(record_t.find(character) != record_t.end()){
                if(record_s.find(character) == record_s.end())
                    record_s[character] = 1;
                else
                    record_s[character] += 1;
            }

            if(record_t.find(character) != record_t.end() &&
               record_s[character] == record_t[character])
                count += 1;
            
            while(unique_required == count){
                character = s[l];

                if(r - l - 1 < ans_length){
                    ans_length = r - l - 1;
                    ans_left = l;
                    ans_right = r;
                }

                record_s[character] -= 1;
                if(record_t.find(character) != record_t.end() &&
                   record_s[character] < record_t[character])
                   count -= 1;
                
                l += 1;

            }
        }

        string result="";
        if(ans_length != INT_MAX)
            for(int i=ans_left; i <= ans_right; ++i)
                result += s[i];      
    
        return result;
    }
};
