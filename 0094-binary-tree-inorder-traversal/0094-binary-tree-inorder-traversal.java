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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        buildTree(root,result);
        return result;
    }
    private static void buildTree(TreeNode root,List<Integer> res){
        if(root==null){
            return;
        }
        buildTree(root.left,res);
        res.add(root.val);
        buildTree(root.right,res);
    }
}