class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOne = -1, freqOne = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                freqOne++;
            }else {
                freqOne = 0;
            }

            maxOne = max(freqOne, maxOne);
        }


        return maxOne;    
    }
};