/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return checkBalanced(root)!=-1;
    }

    private static int checkBalanced(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftheight = checkBalanced(root.left);
        if(leftheight==-1) return -1;
        int rightheight = checkBalanced(root.right);
        if(rightheight==-1) return -1;
        if(Math.abs(leftheight-rightheight)>1){
            return -1;
        }

        return  Math.max(leftheight,rightheight)+1;
    }
}