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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> arr;

        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }

        return helper(root, arr, 0);
    }
private:
    bool helper(TreeNode* root, vector<int>& arr, int idx) {
        if(!root) return false;

        if(idx == arr.size()) return true;

        bool lft = false, rgt = false;

        if(arr[idx] == root->val) {
            lft = helper(root->left, arr, idx+1);
            rgt = helper(root->right, arr, idx+1);
        } else {
            lft = helper(root->left, arr, idx);
            rgt = helper(root->right, arr, idx);
        }

        return lft || rgt;
    }
};