class Solution {
public:
    int fun(vector<int> &arr, int sum, int i, vector<vector<int>> &dp, int offset) {
        int n = arr.size();

        if(sum < -offset || sum > offset) return 0;
        
        if(i == n) {
            if(sum == 0) return 1;

            return 0;
        }
        
        if(dp[i][sum + offset] != -1) return dp[i][sum + offset];
        
        int c1 = fun(arr, sum - arr[i], i + 1, dp, offset);
        int c2 = fun(arr, sum + arr[i], i + 1, dp, offset);

        return dp[i][sum + offset] = c1 + c2;
       
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        if(abs(target) > total) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));
        
        return fun(nums, target, 0, dp, total);
    }
};