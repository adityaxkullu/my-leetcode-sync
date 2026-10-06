class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        if(abs(target) > total) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));

        int offset = total;

        // At i == n;
        // sum == 0 has exactly 1 way
        dp[n][offset] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int sum = -total; sum <= total; sum++) {
                int index = sum + offset;

                int c1 = 0;
                int c2 = 0;
      
                // Put +nums[i]
                if(sum - nums[i] >= -total && sum - nums[i] <= total) {
                    c1 = dp[i + 1][sum - nums[i] + offset];
                }
 
                // Put -nums[i]
                if(sum + nums[i] >= -total && sum + nums[i] <= total) {
                    c2 = dp[i + 1][sum + nums[i] + offset];
                }

                dp[i][index] = c1 + c2;
            }
        }

        return dp[0][target + offset];
    }
};