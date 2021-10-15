class Solution {
    public int numSquares(int n) {
        int ans[] = new int[n+1];
        for(int i = 1;i<=n;i++){
            ans[i] = i;
        }
        
        List<Integer> squares = new ArrayList<>();
        
        for(int i = 2 ; i * i <= n;i++){
            squares.add(i * i);
        }
        
        for(int x : squares){
            ans[x] = 1;
            for(int i = x + 1; i <= n; i++){
                ans[i] = Math.min(ans[i], 1 + ans[i-x]);
            }
        }
        
        return ans[n];
    }
}