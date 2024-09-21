class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i = 1; i < 10; i++) {
            if(i > n) break;
            dfs(ans, i, n);
        }

        return ans;
    }
private:
    void dfs(vector<int>& ans, int cur, const int& n) {
        if(cur > n) return;

        ans.push_back(cur);

        for(int i = 0; i < 10; i++) {
            int nxt = cur * 10 + i;
            if(nxt > n) return;
            dfs(ans, nxt, n);
        }
    }
};
