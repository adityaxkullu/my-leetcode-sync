class Solution {
public:
    int fun(vector<int> &nums, int sum, int i) {
        int n = nums.size();

        if(i == n) {
            if(sum == 0) return 1;
        

            return 0;
        }

        if(sum < nums[i]) {
            return fun(nums, sum, i + 1);
        }

        int c1 = fun(nums, sum - nums[i], i + 1);
        int c2 = fun(nums, sum, i + 1);

        return c1 + c2;
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

        return fun(nums, required, 0);    
    }
};