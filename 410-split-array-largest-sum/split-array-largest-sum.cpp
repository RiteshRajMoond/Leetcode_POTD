class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // int n = nums.size();
        int l = INT_MIN, r = 0;

        for(int& i : nums) {
            l = max(l, i);
            r += i;
        }
        int res = r;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(f(nums, k, mid)) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return res;
    }
private:
    bool f(vector<int>& arr, int k, int sm) {
        int cnt = 1, cur = 0;
        
        for(int& i : arr) {
            if(cur + i > sm) {
                cnt++;
                cur = i;
                if(cnt > k) return false;
            } else cur += i;
        }

        return true;
    }
};