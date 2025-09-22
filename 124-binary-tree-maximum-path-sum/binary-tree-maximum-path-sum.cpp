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
int result=INT_MIN;
int getMax(TreeNode* root){
    if(! root) return 0;
    int left=getMax(root->left);
    int right=getMax(root->right);
    int path=max(left,right)+root->val;
    return max(0,path);
}
void dfs(TreeNode*root){
    if(!root) return ;
    int left=getMax(root->left);
    int right=getMax(root->right);
    result=max(result,left+right+root->val);
    dfs(root->left);
    dfs(root->right);
}
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};