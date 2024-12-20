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
    TreeNode* reverseOddLevels(TreeNode* root) {
        f(root->left, root->right, 1);
        return root;
    }
private:
    void f(TreeNode* r1, TreeNode* r2, int lvl) {
        if(!r1 || !r2) return;

        if(lvl&1) swap(r1->val, r2->val);
        f(r1->left, r2->right, lvl+1);
        f(r1->right, r2->left, lvl+1);
    }
};