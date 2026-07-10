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
    bool isBalanced(TreeNode* root) {
        return findHeight(root)==-1?0:1;
    }

    int findHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left=findHeight(root->left);
        int right=findHeight(root->right);
        if((left==-1)||(right==-1)||(abs(right-left)>1)){
            return -1;
        }
         
        return max(left,right)+1;

    }
};