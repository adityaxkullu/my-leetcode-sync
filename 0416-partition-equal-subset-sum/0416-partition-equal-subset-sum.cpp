class Solution {
public:
    bool fun(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
        int n = arr.size();
        
        if(sum == 0) return true;
        if(i == n) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        if(arr[i] > sum) {
            return dp[i][sum] = fun(arr, sum, i + 1, dp);
        }
        
        return dp[i][sum] = fun(arr, sum - arr[i], i + 1, dp) || fun(arr, sum, i + 1, dp);
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        if(totalSum % 2 == 1) return false;
        int sum = totalSum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return fun(arr, sum, 0, dp);
    }
};