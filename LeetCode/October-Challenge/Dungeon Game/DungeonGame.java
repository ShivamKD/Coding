class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        
        int ans[][] = new int[m+1][n+1];
        
        for(int i = m -1; i>=0;i--){
            for(int j = n-1; j>= 0; j--){
                if(i == m-1 && j == n -1){
                    ans[i][j] = dungeon[i][j];
                }
                else if(i == m-1){
                    ans[i][j] = dungeon[i][j] + ans[i][j+1];
                }
                else if(j == n-1){
                    ans[i][j] = dungeon[i][j] + ans[i+1][j];
                }
                else{
                    ans[i][j] = dungeon[i][j] + Math.max(ans[i+1][j],ans[i][j+1]);
                }
                
                if(ans[i][j] > 0)
                    ans[i][j] = 0;
            }
        }
        
        return -1 * ans[0][0] + 1;
    }
}