class Solution {
public:
    int solve(vector<int> &nums, int i, int freeWill, vector<vector<int>> &dp) {
        int n = nums.size();
        if(i == n) return 0;

        if(dp[i][freeWill] != -1) {
            return dp[i][freeWill];
        }

        if(freeWill == 0) {
            return dp[i][freeWill] = solve(nums, i + 1, 1, dp);
        }

        int c1 = nums[i] + solve(nums, i + 1, 0, dp);
        int c2 = solve(nums, i + 1, 1, dp);

        return dp[i][freeWill] = max(c1, c2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(nums, 0, 1, dp);   
    }
};