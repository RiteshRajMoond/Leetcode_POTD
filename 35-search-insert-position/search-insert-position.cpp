class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);

        if(it == nums.begin()) return 0;
        else return it - nums.begin();
    }
};