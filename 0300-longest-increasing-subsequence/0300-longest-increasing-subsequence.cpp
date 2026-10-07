class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for(int j = 0; j <= n; j++) {
            dp[n][j] = 0;
        }

        for(int i = n -1; i >= 0; i--) {
            for(int prev = i - 1; prev >= -1; prev--) {
                if(prev == -1 || nums[prev] < nums[i]) {
                    int c1 = 1 + dp[i + 1][i + 1];
                    int c2 = dp[i + 1][prev + 1];

                    dp[i][prev + 1] = max(c1, c2);
                } else {
                    dp[i][prev + 1] = dp[i + 1][prev + 1];
                }
            }
        }

        return dp[0][0]; 
    }
};