/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        ListNode* cur = head;
        ListNode* nex = head->next;

        while(nex) {
            int num = gcd(cur->val, nex->val);
            ListNode* temp = new ListNode(num);
            cur->next = temp;
            temp->next = nex;
            cur = nex;
            nex = nex->next;
        }

        return head;
    }
};
