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
   
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [left_rob, left_skip] = dfs(root->left);
        auto [right_rob, right_skip] = dfs(root->right);

       
        int rob_current = root->val + left_skip + right_skip;

       
        int skip_current = max(left_rob, left_skip) + max(right_rob, right_skip);

        return {rob_current, skip_current};
    }

public:
    int rob(TreeNode* root) {
        auto [rob_root, skip_root] = dfs(root);
        return max(rob_root, skip_root);
    }
};