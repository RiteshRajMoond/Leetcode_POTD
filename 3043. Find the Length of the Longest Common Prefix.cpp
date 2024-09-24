class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> sets;

        for(auto i : arr1) {
            string num = to_string(i);
            for(int len = 1; len <= num.size(); len++) {
                sets.insert(num.substr(0, len));
            }
        }

        int ans = 0;

        for(auto i : arr2) {
            int count = 0;
            string temp = to_string(i);

            for(int len = 1; len <= temp.size(); len++) {
                if(sets.count(temp.substr(0, len))) {
                    count++;
                    ans = max(ans, count);
                } else break;
            }
        }

        return ans;

    }
};
