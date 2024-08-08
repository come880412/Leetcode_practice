#define pii pair<int, int>
class Solution {
public:
    unordered_map<string, pii> dir = {
        {"right", {0, 1}},
        {"down", {1, 0}},
        {"left", {0, -1}},
        {"top", {-1, 0}}
    };
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows * cols;
        vector<vector<int>> output;

        pii currPos = {rStart, cStart};
        output.push_back({currPos.first, currPos.second});
        int step = 1;
        int rStep, cStep;
        // Key point: right down | left*2 top*2 | right*3 down*3 | left*4 top*4
        while (output.size() < n) {
            for (int i = 0; i < 2; ++i) {
                if (i == 0 && step % 2 == 1)
                    tie(rStep, cStep) = this->dir["right"];
                else if (i == 0 && step % 2 == 0)
                    tie(rStep, cStep) = this->dir["left"];
                else if (i == 1 && step % 2 == 1) 
                    tie(rStep, cStep) = this->dir["down"];
                else
                    tie(rStep, cStep) = this->dir["top"];
                
                for (int j = 0; j < step; ++j) {
                    currPos.first += rStep;
                    currPos.second += cStep;
                    if (currPos.first < rows && currPos.first >= 0 && currPos.second < cols && currPos.second >= 0)
                        output.push_back({currPos.first, currPos.second});
                    if (output.size() >= n) break;
                }
                if (output.size() >= n) break;
            }
            step++;
        }

        return output;
    }
};