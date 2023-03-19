class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;

        for(int i=0 ; i<nums.size() ; ++i){
            if(record.find(nums[i]) == record.end())
                record[nums[i]] = 1;
            else{
                record[nums[i]] += 1;
            }
        }

        priority_queue<pair<int, int>> pq;
        for (auto i = record.begin(); i != record.end(); ++i) {
            pq.emplace(i->second, i->first); // (value, key)
            // cout << i->first << " "<< i->second << endl;
        }

        vector<int> answer;
        for(int i=0 ; i<k ; ++i){
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};