class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n][2];
        
        dp[0][0] = prices[0];
        for(int i = 1;i<n;i++){
            int profit = 0;
            if(i > 1)
                profit = dp[i-2][1];
            
            dp[i][0] = dp[i-1][0];
            
            if(prices[i] - profit > dp[i][0])
                dp[i][0] = prices[i] - profit;
            //dp[i][0] = Math.min(dp[i-1][0], prices[i] - profit);
            
            dp[i][1] = dp[i-1][1];
            
            if(prices[i] - dp[i-1][0] > dp[i-1][1])
                dp[i][1] = prices[i] - dp[i-1][0];
            //dp[i][1] = Math.max(dp[i-1][1], prices[i] - dp[i-1][0]);
        }
        
        return dp[n-1][1];
    }
}