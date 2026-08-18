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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>arr;
        if(!root) return arr;
        q.push(root);
        while(!q.empty()) {
            int level = q.size();
            vector<int>temp;
            for(int i = 0; i < level; i++) {
                TreeNode* tree = q.front();
                q.pop();
                temp.push_back(tree->val);
                if(tree->left) q.push(tree->left);
                if(tree->right) q.push(tree->right);
            }
            arr.push_back(temp);
        }
        return arr;
    }
};