class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int k = 1; k <= 2; k++) {
                if(k == 2) {
                    dp[i][k] = max(dp[i + 1][k - 1] - prices[i], dp[i + 1][k]);
                } else {
                    dp[i][k] = max(dp[i + 1][k - 1] + prices[i], dp[i + 1][k]);
                }
            }
        }

        return dp[0][k];    
    }
};