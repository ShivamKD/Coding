public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int i = 1;
        while(i<=n){
            int pick = (int)((i * 1L + n) >> 1);
            int g = guess(pick);
            
            if(g == 0)
                return pick;
            if(g > 0){
                i = pick + 1;
            }
            else{
                n = pick - 1;
            }
        }
        return 1;
    }
}