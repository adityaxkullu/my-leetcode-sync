class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        if(totalSum % 2 == 1) return false;
        int sum = totalSum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        for(int j = 0; j <= sum; j++) {
            dp[n][j] = 0;
        }
        
        dp[n][0] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= sum; j++) {
                if(arr[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                }else {
                    dp[i][j] = (dp[i + 1][j - arr[i]] || dp[i + 1][j]);
                }
            }
        }
        
        
        return dp[0][sum];
        
    }
};