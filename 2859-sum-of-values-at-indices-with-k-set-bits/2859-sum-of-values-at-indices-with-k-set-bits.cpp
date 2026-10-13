class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0) return nums[0];

        vector<int> dp(n, 0);
        int ans = 0;

        for(int i = 1; i < n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);

            if(dp[i] == k) {
                ans += nums[i];
            }
        }

        return ans;    
    }
};