/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root ) return "N,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }
    TreeNode* deserializeHelper(queue<string>&q){
        string val=q.front();
        q.pop();
        if(val=="N") return nullptr;
        TreeNode* node=new TreeNode(stoi(val));
        node->left=deserializeHelper(q);
        node->right=deserializeHelper(q);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       stringstream ss(data);
       string val;
       queue<string> q;
       while(getline(ss,val,',')){
        if(!val.empty()){
            q.push(val);
       }
       }
       return deserializeHelper(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));