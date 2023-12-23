// Complexity: O(N)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
            
        vector<string> out;
        for (int i=0; i<numRows; ++i)
            out.push_back("");
        
        int returnNum = 2 * numRows - 2;
        for (int i=0; i<s.length(); ++i) {
            if (i % returnNum < numRows)
                out[i % returnNum] += s[i];
            else {
                out[returnNum - (i % returnNum)] += s[i];
            }
        }
        
        string out_string = "";
        for (int i=0; i<out.size(); ++i) 
            out_string += out[i];
        
        return out_string;
    }
};