class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st; // ele
        for(int& i : arr) {
            if(!st.empty() && i < st.top()) {
                int tp = st.top();
                while(!st.empty() && i < st.top()) st.pop();
                st.push(tp);
            } else st.push(i);
        }

        return st.size();
    }
};