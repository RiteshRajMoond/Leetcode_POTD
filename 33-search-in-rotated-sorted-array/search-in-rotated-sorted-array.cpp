class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }

        int rot = l;

        if(nums.back() >= target) {
            auto it = lower_bound(nums.begin()+rot, nums.end(), target);
            if(*it == target) return it - nums.begin();
        } else {
            auto it = lower_bound(nums.begin(), nums.begin()+rot, target);
            if(*it == target) return it - nums.begin();
        }

        return -1;
    }
};