class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            int p = (mid == 0) ? INT_MIN : nums[mid-1];
            int n = (mid == nums.size()-1) ? INT_MIN : nums[mid+1];
            if(nums[mid] > p && nums[mid] > n) return mid;
            else if(p > nums[mid]) r = mid;
            else l = mid+1;
        }
        return l;
    }
};