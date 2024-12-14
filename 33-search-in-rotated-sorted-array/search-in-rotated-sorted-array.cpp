class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high]) low = mid+1;
            else high = mid;
        }

        int rot = low;

        if(target <= nums[n-1]) {
            auto it = lower_bound(nums.begin() + rot, nums.end(), target);
            if(it != nums.end() && *it == target) return it - nums.begin();
        } else {
            auto it = lower_bound(nums.begin(), nums.begin() + rot, target);
            if(it != nums.end() && *it == target) return it - nums.begin();
        }

        return -1;
    }
};