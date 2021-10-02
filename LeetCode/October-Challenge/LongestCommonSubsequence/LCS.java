class Solution {
    
    int dp[][] = new int[1001][1001];
    int max = 0;
    
    private int lcs(String s, String t, int n, int m){
        if(n == 0 || m == 0)
            return 0;
        
        if(dp[n-1][m-1] != 0)
            return dp[n-1][m-1];
        
        if(s.charAt(n-1) == t.charAt(m-1)){
            dp[n-1][m-1] = 1 + lcs(s,t,n-1,m-1);
            max = Math.max(max, dp[n-1][m-1]);
            return dp[n-1][m-1];
        }
        
        
            dp[n-1][m-1] = Math.max(lcs(s,t, n-1,m),lcs(s,t,n, m-1));
            max = Math.max(max, dp[n-1][m-1]);
            return dp[n-1][m-1];
        
    }
    public int longestCommonSubsequence(String text1, String text2) {
        
        lcs(text1, text2, text1.length(), text2.length());
        return max;
    }
}