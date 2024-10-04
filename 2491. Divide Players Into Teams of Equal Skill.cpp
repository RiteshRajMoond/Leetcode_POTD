class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n&1 == 1) return -1;
        sort(skill.begin(), skill.end());
        int skillLevel = skill[0] + skill[n-1];
        long long ans = 0;
        int start = 0, end = n-1;
        while(start < end) {
            if(skillLevel != skill[start] + skill[end]) return -1;
            ans += (long long) (skill[start] * skill[end]);
            start++;
            end--;
        }
        return ans;
    }
};
