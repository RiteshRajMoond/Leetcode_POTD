
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        vector<vector<int>> ans(m, vector<int> (n, -1));
        
        int rowS = 0;
        int rowL = m-1;
        int colS = 0;
        int colL = n-1;

        while(head) {
            // Left
            for(int i = colS; i <= colL && head; i++) {
                ans[rowS][i] = head->val;
                head = head->next;
            }
            rowS++;

            // Down
            for(int i = rowS ; i <= rowL && head; i++) {
                ans[i][colL] = head->val;
                head = head->next;
            }
            colL--;

            // Right
            for(int i = colL; i >= colS && head; i--) {
                ans[rowL][i] = head->val;
                head = head->next;
            }
            rowL--;

            // Up
            for(int i = rowL; i >= rowS && head; i--) {
                ans[i][colS] = head->val;
                head = head->next;
            }
            colS++;
        }

        return ans;

    }
};
