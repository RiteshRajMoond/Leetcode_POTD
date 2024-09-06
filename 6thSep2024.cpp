class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

        unordered_set<int> st;

        for (auto i : nums)
            st.insert(i);

        while (head) {
            if (st.find(head->val) != st.end()) {
                if (head->next) {
                    head = head->next;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        ListNode* temp = head;

        while (temp && temp->next) {
            int n = temp->next->val;
            if (st.find(n) != st.end()) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};