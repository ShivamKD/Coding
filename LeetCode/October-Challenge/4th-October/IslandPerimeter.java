class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length, n = grid[0].length, ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    
                    if(i > 0){
                        if(grid[i-1][j] != 1)
                            ans++;
                    }
                    else{
                        ans++;
                    }
                    if(i < m-1){
                        if(grid[i+1][j] != 1)
                            ans++;
                    } else {
                        ans++;
                    }
                    
                    if( j > 0){
                        if( grid[i][j-1] != 1)
                            ans++;
                    } else {
                        ans++;
                    }
                    
                    if( j < n-1){
                        if(grid[i][j+1] != 1)
                            ans++;
                    } else {
                        ans++;
                    }
                    
                }
            }
        }
        return ans;
    }
}