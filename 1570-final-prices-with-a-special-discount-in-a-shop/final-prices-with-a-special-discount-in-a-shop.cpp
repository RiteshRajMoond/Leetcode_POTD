class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);

        stack<int> st; // elements

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() > prices[i]) st.pop();
            int dis = st.empty() ? 0 : st.top();
            res[i] = prices[i] - dis;
            st.push(prices[i]);
        }

        return res;
    }
};