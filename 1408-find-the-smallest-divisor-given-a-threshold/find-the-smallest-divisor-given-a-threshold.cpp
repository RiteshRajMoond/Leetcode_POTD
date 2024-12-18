class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = 0, r = INT_MIN;
        for(int& i : nums) {
            n++;
            r = max(r, i);
        }
        if(n == threshold) return r;
        int res = r, l = 1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(f(nums, threshold, mid)) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
        }

        return res;
    }
private:
    bool f(vector<int>& nums, int thres, int div) {
        int sum = 0;
        for(int& i : nums) {
            sum += (i + div - 1)/div;
        }
        return sum <= thres;
    }
};