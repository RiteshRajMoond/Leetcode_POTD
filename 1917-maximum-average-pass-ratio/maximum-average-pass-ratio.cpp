class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto delta = [](int pass, int total) -> double {
            return (double)(pass+1)/(total+1) - (double)pass/total;
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        for(const auto& i : classes) pq.push({delta(i[0], i[1]), {i[0], i[1]}});
        
        int extra = extraStudents;
        while(extra--) {
            auto [del, info] = pq.top();
            pq.pop();

            int p = info.first;
            int t = info.second;
            p++, t++;
            pq.push({delta(p, t), {p, t}});
        }

        double res = 0;
        while(!pq.empty()) {
            auto [del, info] = pq.top();
            pq.pop();
            res += (double) info.first/info.second;
        }

        return res/classes.size();
    }
};