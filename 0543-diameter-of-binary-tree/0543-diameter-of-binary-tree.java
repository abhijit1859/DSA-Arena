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
    private static int diameter=0;
    public int diameterOfBinaryTree(TreeNode root) {
         diameter = 0; 
        int diam = diameter(root);
        return diameter;
        
    }
    private static int diameter(TreeNode root){
        if(root==null){
            return 0;
        }
        int maxLeftHeight=diameter(root.left);
        int maxRightHeight=diameter(root.right);
        diameter = Math.max(diameter,maxLeftHeight+maxRightHeight);
        return Math.max(maxLeftHeight,maxRightHeight)+1;

     }
}