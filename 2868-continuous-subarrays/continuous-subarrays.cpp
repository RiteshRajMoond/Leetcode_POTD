class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), i = 0;
        multiset<int> st;
        long long res = 0;
        for(int j = 0; j < n; j++) {
            st.insert(nums[j]);
            while(*st.rbegin() - *st.begin() > 2) st.erase(st.find(nums[i++]));
            res += j-i+1;
        }
        return res;
    }
};