class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        int rank = 1;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            if(mp.count(temp[i]) == 0) {
                mp[temp[i]] = rank++;
            } 
        }

        temp.clear();

        for(auto i : arr) {
            temp.push_back(mp[i]);
        }

        return temp;
        
    }
};
