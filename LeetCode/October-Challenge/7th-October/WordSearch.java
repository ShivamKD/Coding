class Solution {
        
    
    private boolean dfs(int i, int j, int m, int n,char board[][], boolean visited[][], String word, int len){
        if(len == word.length()){
            
            return true;
        }
            
        visited[i][j] = true;
        
        if(i < m-1){
            if(!visited[i+1][j] && board[i+1][j] == word.charAt(len)){
                if(dfs(i+1,j,m,n,board,visited,word,len+1))
                    return true;
            }
        }
        
        if(j < n-1){
            if(!visited[i][j+1] && board[i][j+1] == word.charAt(len)){
                
                if(dfs(i,j+1,m,n,board,visited,word,len+1))
                    return true;
            }
        }
        
        if(i > 0){
            if(!visited[i-1][j] && board[i-1][j] == word.charAt(len)){
                if(dfs(i-1,j,m,n,board,visited,word,len+1))
                    return true;
            }
        }
        
        if(j > 0){
            if(!visited[i][j-1] && board[i][j-1] == word.charAt(len)){
                if(dfs(i,j-1,m,n,board,visited,word,len+1))
                    return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        
        boolean visited[][] = new boolean[m][n];
        for(int i = 0;i<m;i++){
            Arrays.fill(visited[i], false);
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word.charAt(0)){
                    
                    if(dfs(i, j, m, n, board, visited, word, 1))
                        return true;
                }
            }
        }
        
        return false;
        
    }
}

