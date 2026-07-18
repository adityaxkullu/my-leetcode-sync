class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int right = 0;
        // find first non-negative element
        while(right < n && nums[right] < 0) {
            right++;
        }
        // last negative element
        int left = right - 1;
        
        // merge the two sorted parts
        while(left >= 0 && right < n) {
            int sqLeft = nums[left] * nums[left];
            int sqRight = nums[right] * nums[right];

            if(sqLeft <= sqRight) {
                ans.push_back(sqLeft);
                left--;
            }else {
                ans.push_back(sqRight);
                right++;
            } 
        }
  
        // remaining negative numbers
        while(left >= 0) {
            ans.push_back(nums[left] * nums[left]);
            left--;
        }

        // remaining positive numbers
        while(right < n) {
            ans.push_back(nums[right] * nums[right]);
            right++;
        }

        return ans;   
    }
};