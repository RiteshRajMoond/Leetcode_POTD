class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, r = 0;
        for(int& i : weights) l = max(l, i), r += i;
        int res = r;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(f(weights, days, mid)) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return res;
    }
private:
    bool f(vector<int>& arr, int days, int mid) {
        int cur = 0, total = 1;
        for(int& i : arr) {
            if(i + cur > mid) {
                total++;
                cur = i;
                if(total > days) return false;
            } else cur += i;
        }
        return true;
    }
};