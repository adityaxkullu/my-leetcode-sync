class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {
            int start = 0;
            int end = res.size() - 1;
            int index = res.size();

            while(start <= end) {
                int mid = start + (end - start) / 2;

                if(res[mid] >= nums[i]) {
                    index = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            if(index == res.size()) {
                res.push_back(nums[i]);
            } else {
                res[index] = nums[i];
            }
        }

        return res.size();
    }
};