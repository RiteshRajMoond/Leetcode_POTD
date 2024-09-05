class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int sum = 0;
        for(auto i : rolls) sum += i;

        int x = mean * (m+n) - sum;

        if(x < n || x > 6 * n) 
            return {};

        vector<int> ans(n, 1);
        x -= n;

        for(int i = 0; i < n && x > 0; i++) {
            int add = min(5, x);
            ans[i] += add;
            x -= add;
        }

        return ans;
    }
};