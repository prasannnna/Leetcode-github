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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>arr;
        if(!root) return arr;
        q.push(root);
        while(!q.empty()) {
            int level = q.size();
            arr.push_back(q.front()->val);
            for(int i = 0; i < level; i++) {
                TreeNode* t = q.front();
                q.pop();
                if(t->right)q.push(t->right);
                if(t->left)q.push(t->left);
            }
            
        }
        return arr;
    }
};