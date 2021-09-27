class Solution {
    
    public int shortestPath(int[][] grid, int k) {
        int rows = grid.length, cols = grid[0].length;
        
        int target[]  = {rows - 1, cols - 1};
        
        if( k >= rows + cols - 2)
            return rows + cols - 2;
        
        Deque<State> queue = new LinkedList<>();
        HashSet<State> seen = new HashSet<>();
        
        State start = new State(0, 0, 0, k);
        queue.addLast(start);
        seen.add(start);
        
        while(!queue.isEmpty()){
            State current = queue.pollFirst();
            
            if(target[0] == current.row && target[1] == current.col)
                return current.steps;
            
            int nextState[] = {current.row + 1, current.col, current.row, current.col + 1, current.row - 1, current.col, current.row, current.col - 1};
            
            for(int  i = 0; i< nextState.length;i+=2){
                int nextRow = nextState[i];
                int nextCol = nextState[i+1];
                
                if(nextRow >=0 && nextRow < rows && nextCol >= 0 && nextCol < cols){
                    int left = current.k - grid[nextRow][nextCol];
                    if(left >= 0){
                        State newState = new State(nextRow, nextCol, current.steps + 1, left);
                        if(!seen.contains(newState)){
                            queue.addLast(newState);
                            seen.add(newState);
                        }
                    }
                }
            }
        }
        return -1;
    }
}

class State{
    int row, col, steps, k;
    State(int row, int col, int steps, int k){
        this.row = row;
        this.col = col;
        this.steps = steps;
        this.k = k;
        
    }
    
    
   @Override
    public int hashCode() {
        return (this.row + 1) * (this.col + 1) * this.k;
    }
    
    @Override
    public boolean equals(Object o){
        if ( !(o instanceof State))
            return false;
        
        State s = (State)o;
        return s.row == this.row && s.col == this.col && s.k == this.k;
    }
}