class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mVal = 0;
        for(const int& num: nums) mVal |= num;
        int ans = recursion(nums, mVal, 0, n, 0);
        return ans;
    }
private:
    int recursion(vector<int>& nums, const int& tar, int idx, const int& n, int cur) {
        if(idx >= n) return (tar == cur) ? 1 : 0;
        int ans = 0;
        // inc and not-inc
        ans += (recursion(nums, tar, idx+1, n, cur | nums[idx]) + recursion(nums, tar, idx+1, n, cur));
        return ans;
    }
};
