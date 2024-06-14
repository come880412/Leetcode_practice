class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> nextGreaterMap;
        stack<int> s;
        s.push(nums2[0]);
        for (int i = 1; i < n2; ++i) {
            while (!s.empty() && nums2[i] > s.top()) {
                int popKey = s.top();
                nextGreaterMap[popKey] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            int popKey = s.top();
            nextGreaterMap[popKey] = -1;
            s.pop();
        }

        vector<int> result;
        for (int i = 0; i < n1; ++i) result.push_back(nextGreaterMap[nums1[i]]);

        return result;
    }
};