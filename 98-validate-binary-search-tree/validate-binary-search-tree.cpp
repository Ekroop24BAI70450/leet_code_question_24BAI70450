class Solution {
private:
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) {
            return true;
        }

       
        if (minNode != nullptr && root->val <= minNode->val) {
            return false;
        }
        if (maxNode != nullptr && root->val >= maxNode->val) {
            return false;
        }

     
        return isValid(root->left, minNode, root) &&
               isValid(root->right, root, maxNode);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};