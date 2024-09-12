class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

        unordered_map<char, int> mp;

        for (auto i : allowed)
            mp[i] = 1;

        int ans = words.size();

        for (auto i : words) {
            for (auto j : i) {
                if (mp[j] == 0) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
