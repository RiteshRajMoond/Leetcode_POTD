class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = INT_MIN, el2 = INT_MIN, cnt1 = 0, cnt2 = 0;

        for(int& i : nums) {
            if(cnt1 == 0 && el2 != i) el1 = i, cnt1 = 1;
            else if (cnt2 == 0 && el1 != i) el2 = i, cnt2 = 1;
            else if(i == el1) cnt1++;
            else if(i == el2) cnt2++;
            else cnt1--, cnt2--;
        }

        cnt1 = 0, cnt2 = 0;

        for(int& i : nums) {
            if(i == el1) cnt1++;
            else if(i == el2) cnt2++;
        }

        vector<int> res;
        if(cnt1 > nums.size()/3) res.push_back(el1);
        if(cnt2 > nums.size()/3) res.push_back(el2);

        return res;
    }
};