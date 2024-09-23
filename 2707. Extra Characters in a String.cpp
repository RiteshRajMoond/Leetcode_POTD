class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(), dict.end());

        vector<int> dp(s.size(), -1);

        return helper(0, s, st, dp);
    }

private:
    int helper(int idx, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (idx >= s.size())
            return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = 1 + helper(idx + 1, s, st, dp);

        for (int len = 1; len + idx <= s.size(); len++) {
            string word = s.substr(idx, len);

            if (st.count(word)) {
                ans = min(ans, helper(idx + len, s, st, dp));
            }
        }

        return dp[idx] = ans;
    }
};
