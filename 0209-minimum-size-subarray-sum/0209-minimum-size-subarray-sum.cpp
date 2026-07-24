class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0, sum = 0, res = n + 1;

        while(high < n) {
            sum += nums[high];

            while(sum >= target) {
                int length = high - low + 1;
                res = min(res, length);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(res == n + 1) return 0;
        
         return res;    
    }
};