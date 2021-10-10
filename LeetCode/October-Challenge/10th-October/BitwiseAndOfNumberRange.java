class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        
        if(left == right)
            return right;
        
        int ans = 0;
        
        for(int i =30;i>0;i--){
            
            if(((1<<i) & left) != 0){
                
                int mask = (int)((1L<<(i+1)) - 1);
                int remaining = mask - left & mask;
                
                if(diff <= remaining)
                    ans |= (int)((1L<<(i)));
            }
        }
                                 
        return ans;
    }
}