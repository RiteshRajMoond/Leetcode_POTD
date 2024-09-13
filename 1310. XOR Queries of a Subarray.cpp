class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        vector<int> xorNums;
        int n = 0;

        for(auto i : arr) {
            n ^= i;
            xorNums.push_back(n);
        }

        vector<int> ans;

        for(auto i : queries) {
            int left = i[0];
            int right = i[1];

            int r = xorNums[right];

            if(left > 0) {
                r ^= xorNums[left-1];
            }

            ans.push_back(r);
        }

        return ans;
    }
};
