class Trie {
    
    class Node{
        Node children[];
        boolean isEndOfWord;
        Node(){
            children = new Node[26];
            isEndOfWord = false;
        }
    }

    Node root;
    
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node ptr = root;
        for(char ch : word.toCharArray()){
            int index = ch - 'a';
            if(ptr.children[index] == null)
                ptr.children[index] = new Node();
            
            ptr = ptr.children[index];
        }
        
        ptr.isEndOfWord = true;
    }
    
    public boolean search(String word) {
        Node ptr = root;
        
        for(char ch: word.toCharArray()){
            int index = ch - 'a';
            if(ptr.children[index] == null)
                return false;
            
            ptr = ptr.children[index];
        }
        
        return ptr.isEndOfWord;
    }
    
    public boolean startsWith(String prefix) {
        Node ptr = root;
        
        for(char ch: prefix.toCharArray()){
            int index = ch - 'a';
            if(ptr.children[index] == null)
                return false;
            
            ptr = ptr.children[index];
        }
        
        return true;
    }
}