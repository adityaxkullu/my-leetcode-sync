class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        if(abs(target) > total) return 0;
        if((total + target) % 2 != 0) return 0;

        int required = (total + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(required + 1, -1));

        for(int j = 0; j <= required; j++) {
            dp[n][j] = 0;
        }  

        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= required; j++) {
                if(nums[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j - nums[i]] + dp[i + 1][j];
                }
            }
        } 

        return dp[0][required];
    }
};