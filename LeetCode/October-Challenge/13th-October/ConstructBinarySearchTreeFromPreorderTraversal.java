class Solution {
    
    private TreeNode bstUtil(int preorder[], int start, int end){
        
        if(end < start)
            return null;
        TreeNode current = new TreeNode(preorder[start]);
        int mid = end + 1;
        for(int i = start + 1; i <= end; i++){
            if(preorder[i] > preorder[start]){
                mid = i;
                break;
            }
        }
        
        current.left = bstUtil(preorder, start + 1, mid - 1);
        current.right = bstUtil(preorder, mid, end);
        
        return current;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = bstUtil(preorder, 0, preorder.length-1);
        return root;
    }
}