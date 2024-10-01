class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            int num = ((i % k) + k) % k;
            mp[num]++;
        }
        for (auto i : mp) {
            if (i.first == 0) {
                if (i.second % 2 != 0)
                    return false;
            } else if (mp[i.first] != mp[k - i.first])
                return false;
        }
        return true;
    }
};
