class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
       int ans = 0;
       vector<vector<int>> cache(grid.size(), vector<int>(grid[0].size(), -1));
       for(int i = 0; i < grid.size(); i++) {
        ans = max(ans, helper(grid, i, 0, -1, cache));
       }
       return ans == 1 ? 0 : ans-1;
    }
private:
    int helper(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<int>>& cache) {
        if(i < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev) return 0;

        if(cache[i][j] != -1) return cache[i][j];

        int right = helper(grid, i, j+1, grid[i][j], cache);
        int pdig = helper(grid, i+1, j+1, grid[i][j], cache);
        int sdig = helper(grid, i-1, j+1, grid[i][j], cache);

        return cache[i][j] = 1 + max(right, max(pdig, sdig));
    }
};
