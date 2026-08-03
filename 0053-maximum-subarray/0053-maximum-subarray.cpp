class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int bestEnding = 0, ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            int v1 = bestEnding + nums[i];
            bestEnding = max(v1, nums[i]);
            
            ans = max(ans, bestEnding);   
        }

        return ans;    
    }
};