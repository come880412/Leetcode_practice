class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        
        int ans = 0;
        if (n % 2 == 0 && m % 2 == 1) {
            for (int i = 0; i < n; ++i)
                ans ^= nums1[i];
        }
        else if (n % 2 == 1 && m % 2 == 0) {
            for (int i = 0; i < m; ++i)
                ans ^= nums2[i];
        }
        else if (n % 2 == 1 && m % 2 == 1) {
            for (int i = 0; i < n; ++i)
                ans ^= nums1[i];
            for (int i = 0; i < m; ++i)
                ans ^= nums2[i];
        }
        return ans;
    }
};