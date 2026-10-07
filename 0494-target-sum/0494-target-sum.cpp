class Solution {
public:
    int fun(vector<int> &nums, int sum, int i, vector<vector<int>> &dp) {
        int n = nums.size();

        if(i == n) {
            if(sum == 0) return 1;
            
            return 0;
        }
 
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        if(sum < nums[i]) {
            return dp[i][sum] = fun(nums, sum, i + 1, dp);
        }

        int c1 = fun(nums, sum - nums[i], i + 1, dp);
        int c2 = fun(nums, sum, i + 1, dp);

        return dp[i][sum] = c1 + c2;
    }

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

        return fun(nums, required, 0, dp);    
    }
};