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
int height(TreeNode* root) {
    if(!root) return 0;
    int lt = 1 + height(root->left);
    int rt = 1 + height(root->right);
    return max(rt, lt);
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(isBalanced(root->left) && isBalanced(root->right)) {
            int lt = height(root->left);
            int rt = height(root->right);
            if(abs(lt - rt) < 2) return true;
        }
        return false;
    }
};