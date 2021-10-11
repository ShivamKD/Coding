class Solution {
    int max = 0;
    
    private int diameterUtil(TreeNode root){
        if(root == null)
            return 0;
        
        int left = diameterUtil(root.left);
        int right = diameterUtil(root.right);
        
        max = Math.max(max, 1 + left + right);
        
        return 1 + Math.max(left, right);
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        diameterUtil(root);
        return max-1;
        
    }
}