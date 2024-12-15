class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>> res;

        // sort
        sort(inter.begin(), inter.end());

        for(auto& i : inter) {
            if(res.empty() || res.back()[1] < i[0]) res.push_back(i);
            else res.back()[1] = max(res.back()[1], i[1]);
        }
        return res;
    }
};