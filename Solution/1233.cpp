class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), []
                (const std::string& first, const std::string& second){
                    return first.size() < second.size();
                });
        unordered_map<string, int> map;

        for (string subName : folder) {
            size_t findSlash = subName.find('/');
            string tmpStr;
            while (findSlash != string::npos) {
                size_t nextSlash = subName.find('/', findSlash+1);
                if (tmpStr != "") tmpStr += "/";
                tmpStr += subName.substr(findSlash+1, nextSlash-findSlash-1);
                if (map.find(tmpStr) != map.end()) break;
                
                findSlash = nextSlash;
            }
            if (map.find(tmpStr) == map.end()) map[tmpStr] = 1;
        }

        vector<string> ans;
        for (auto const [key, value] : map) ans.emplace_back("/"+key);
        return ans;
    }
};