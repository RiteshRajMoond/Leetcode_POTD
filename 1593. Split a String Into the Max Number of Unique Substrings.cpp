class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return helper(s, 0, st);
    }
private:
    int helper(const string& s, int start, unordered_set<string>& st) {
        if(start == s.size()) return 0;

        int ans = 0;
        
        for(int end = start; end < s.size(); end++) {
            string temp = s.substr(start, end - start + 1);

            if(!st.count(temp)) {
                st.insert(temp);
                ans = max(ans, 1 + helper(s, end+1, st));
                st.erase(temp);
            }
        }
        return ans;
    }
};
