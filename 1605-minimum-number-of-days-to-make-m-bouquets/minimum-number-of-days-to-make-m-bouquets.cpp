class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long )m*k > n) return -1;

        int l = 1, r = 1e9;
        int res = -1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(f(bloomDay, m, k, mid)) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
        }

        return res;
    }
private:
    bool f(vector<int>& arr, int m, int k, int day) {
        int cnt = 0, total = 0;

        for(int& i : arr) {
            if(day >= i) {
                cnt++;
                if(cnt == k) total++, cnt = 0;
            } else cnt = 0;
        }

        return total >= m;
    }
};