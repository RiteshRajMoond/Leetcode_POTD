class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans= "";
        priority_queue<pair<int, char>>pq;
        
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int n = ans.size();
            if(n > 1 && ans[n-1] == temp.second && ans[n-2] == temp.second){
                if(pq.empty()) break;

                auto temp2 = pq.top();
                pq.pop();

                ans += temp2.second;

                temp2.first--;
                if(temp2.first > 0) pq.push(temp2);
            } else {
                ans += temp.second;
                temp.first--;
            }

            if(temp.first > 0) pq.push(temp);
        }
        return ans;
    }
};
