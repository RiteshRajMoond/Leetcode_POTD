class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        int target = sum % p;
        if(target == 0) return 0;

        unordered_map<int, int> pref;
        pref[0] = -1;
        sum = 0;
        int len = n;
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            int rem = (sum - target + p) % p;

            if(pref.find(rem) != pref.end()) len = min(len, i - pref[rem]);

            pref[sum] = i;
        }
        return len == n ? -1 : len;
    }
};
