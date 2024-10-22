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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            mp[temp.second] += temp.first->val;

            if(temp.first->left) q.push({temp.first->left, temp.second+1});
            if(temp.first->right) q.push({temp.first->right, temp.second+1});
        }

        int n = mp.size();
        if(n < k) return -1;
        
        vector<long long> v;
        for(auto i : mp) v.push_back(i.second);
        sort(v.begin(), v.end());
        return v[n - k];        
    }
};
