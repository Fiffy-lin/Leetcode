// /**
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
    vector<int> val;
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        int mindis=INT_MAX;
        for(int i=0;i<val.size()-1;++i)
            mindis=min(mindis,val[i+1]-val[i]);
        return mindis;
    }
    void helper(TreeNode *root){
        if(!root) return;
        helper(root->left);
        val.emplace_back(root->val);
        helper(root->right);
    }
};