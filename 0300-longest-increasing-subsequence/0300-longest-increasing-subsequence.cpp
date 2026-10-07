class Solution {
public:
    int fun(vector<int> &nums, int i, int prev, vector<vector<int>> &dp) {
        int n = nums.size();

        if(i == n) return 0;
        
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        if(prev == -1 || nums[i] > nums[prev]) {
            int c1 = 1 + fun(nums, i + 1, i, dp);
            int c2 = fun(nums, i + 1, prev, dp);

            return dp[i][prev + 1] = max(c1, c2);
        }

        return dp[i][prev + 1] = fun(nums, i + 1, prev, dp);
    }
 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return fun(nums, 0, -1, dp);    
    }
};