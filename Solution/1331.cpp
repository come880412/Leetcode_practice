class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> rank;
        vector<int> result;

        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());

        int currRank = 1;
        for (int i = 0; i < n; ++i) {
            int currNum = sortedArr[i];
            if (i == 0) rank[currNum] = currRank;
            else {
                int prevNum = sortedArr[i-1];
                if (prevNum != currNum) currRank++;
                rank[currNum] = currRank;
            }
        }

        for (int num : arr) {
            result.push_back(rank[num]);
        }

        return result;
    }
};