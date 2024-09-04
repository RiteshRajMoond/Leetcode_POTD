class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        unordered_set <string> st;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // N E S W

        for(auto i : obs) {
            st.insert(to_string(i[0]) + "," + to_string(i[1]));
        }

        int x = 0, y = 0, dir = 0, ans = 0;

        for(auto i : commands) {
            if(i == -1) {
                dir = (dir + 1) % 4;
            } else if(i == -2) {
                dir = (dir + 3) % 4;
            } else {
                while(i--) {
                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];

                    if(st.find(to_string(nx) + "," + to_string(ny)) != st.end()) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;

    }
};