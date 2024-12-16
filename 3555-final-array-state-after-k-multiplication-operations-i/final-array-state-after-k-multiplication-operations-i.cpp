class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();

        for(int i = 0; i < n; i++) pq.push({nums[i], i}); //ele , idx

        for(int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            top.first *= multiplier;
            pq.push(top);
        }

        vector<int> res(n);
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res[top.second] = top.first;
        }
        return res;
    }
};