class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        int num = skill[0] + skill[n-1];
        long long ans = skill[0] * skill[n-1];

        int l = 1, r = n - 2;
        while (l < r) {
            if (skill[l] + skill[r] != num) return -1;
            ans += (skill[l] * skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};