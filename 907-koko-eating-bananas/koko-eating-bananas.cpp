class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        
        int l = 1, r = piles.back(), res = piles.back();
        while(l < r) {
            int mid = l + (r-l)/2;

            int time = 0;
            for(int& b : piles) 
                time += (b + mid - 1) / mid;
            
            if(time <= h) {
                res = min(res, mid);
                r = mid;
            } else l = mid+1;
        }
        return res;
    }
};