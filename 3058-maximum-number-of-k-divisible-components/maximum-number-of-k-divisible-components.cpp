#define ll long long

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int res = 0;
        auto dfs = [&](auto& self, int cur, int par) -> ll {
            ll total = values[cur];

            for(int& i : adj[cur]) {
                if(i != par)
                    total += self(self, i, cur);
            }

            if(total%k == 0) res++;
            return total;
        };

        dfs(dfs, 0, -1);
        return res;
    }
};