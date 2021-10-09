class Solution {
    class Node{
        Node children[];
        Node(){
            children = new Node[26];
        }
    }
    
    class Trie{
        Node root;
        Trie(){
            root = new Node();
        }
        
        void insert(String word){
            Node ptr = root;
            
            for(char ch : word.toCharArray()){
                int index = ch - 'a';
                
                if(ptr.children[index] == null){
                    ptr.children[index] = new Node();
                }
                
                ptr = ptr.children[index];
                
            }
        }
        
        boolean present(String word){
            Node ptr = root;
            
            for(char ch: word.toCharArray()){
                int index = ch - 'a';
                
                if(ptr.children[index] == null)
                    return false;
                
                ptr = ptr.children[index];
            }
            
            return true;
        }
    }
    Trie trie = new Trie();
    
    void insert(int i, int j, char board[][], boolean visited[][], String word){
        
        if(visited[i][j] || word.length() > 10){
                       
            return ;
        }
        
        trie.insert(word);
        
        visited[i][j] = true;
        
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        for(int k = 0;k<4;k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if((r >= 0 && r < board.length) && (c >= 0 && c < board[0].length) ){
                
                insert(r,c,board,visited, word + board[r][c]);
                
            }
        }
        
        visited[i][j] = false;
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        ;
        
        int m = board.length, n = board[0].length;
        boolean visited[][] = new boolean[m][n];
        for(int i = 0;i<m;i++){
            Arrays.fill(visited[i], false);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                insert(i,j,board,visited,"" + board[i][j]);
            }
        }
        
        List<String> answer = new ArrayList<>();
        
        for(String word : words){
            if(trie.present(word)){
                answer.add(word);
            }
        }
        return answer;
    }
}