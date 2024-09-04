#define pii pair<int, int>

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int n = commands.size();

        for (auto const& ob : obstacles) {
            xObMap[ob[0]].insert(ob[1]);
            yObMap[ob[1]].insert(ob[0]);
        }

        int dir = 0;
        pii curr = {0, 0};
        int maxDist = 0;
        for (const int command: commands) {
            if (command == -1) dir = (dir + 1) % 4;
            else if (command == -2) dir = (dir + 3) % 4;
            else {
                auto [currX, currY] = curr;
                auto [dirX, dirY] = dirs[dir];
                int k = command * ((dir == 0 || dir == 2) ? dirY : dirX);
                int boundary = INT_MAX;
                switch(dir) {
                    case 0: // North
                        boundary = getBoundary(xObMap, currX, currY, true);
                        currY = min(currY + k, boundary - 1);
                        break;
                    case 1: // East
                        boundary = getBoundary(yObMap, currY, currX, true);
                        currX = min(currX + k, boundary - 1);
                        break;
                    case 2: // South
                        boundary = getBoundary(xObMap, currX, currY, false);
                        currY = max(currY + k, boundary + 1);
                        break;
                    case 3: // West
                        boundary = getBoundary(yObMap, currY, currX, false);
                        currX = max(currX + k, boundary + 1);
                        break;
                }
                curr.first = currX;
                curr.second = currY;
            }
            int dist = curr.first*curr.first + curr.second*curr.second;
            maxDist = max(maxDist, dist);
        }
        return maxDist;
    }

    int getBoundary(const unordered_map<int, set<int>>& obMap, int currCoord, int dirCoord, bool isForward) {
        if (obMap.find(currCoord) != obMap.end()) {
            auto it = obMap.at(currCoord).upper_bound(dirCoord);
            if (isForward) {
                if (it != obMap.at(currCoord).end() && *it != dirCoord) return *it;
                else return INT_MAX;
            } else {
                if (it != obMap.at(currCoord).begin() && *prev(it) != dirCoord) return *prev(it);
                else return INT_MIN;
            }
        }
        return isForward ? INT_MAX : INT_MIN;
}

private:
    unordered_map<int, set<int>> xObMap, yObMap;
    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};