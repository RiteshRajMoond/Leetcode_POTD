#define ll long long

class Solution {
public:
    vector<vector<int>> adj;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        for(auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int res = 0;
        dfs(res, values, 0, -1, k);
        return res;
    }
private:
    ll dfs(int& res, vector<int>& val, int cur, int par, const int& k) {
        ll total = val[cur];

        for(auto& i : adj[cur]) {
            if(i == par) continue;
            total += dfs(res, val, i, cur, k);
        }

        if(total % k == 0) res++;
        return total;
    }
};