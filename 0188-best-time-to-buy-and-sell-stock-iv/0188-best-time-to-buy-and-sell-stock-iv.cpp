class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2 * k + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 2 * k; j >= 1; j--) {
                if(j % 2 == 0) {
                    dp[j] = max(dp[j - 1] - prices[i], dp[j]);
                } else {
                    dp[j] = max(dp[j - 1] + prices[i], dp[j]);
                }
            }
        }

        return dp[2 * k];    
    }
};