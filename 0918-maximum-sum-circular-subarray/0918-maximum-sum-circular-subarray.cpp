class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n = a.size();
        int totalSum = a[0];

        int maxEnding = a[0], maxSum = a[0];
        int minEnding = a[0], minSum = a[0];

        for(int i = 1; i < n; i++) {
            totalSum += a[i];

            maxEnding = max((maxEnding + a[i]), a[i]);
            maxSum = max(maxEnding, maxSum);

            minEnding = min((minEnding + a[i]), a[i]);
            minSum = min(minEnding, minSum);
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum);    
    }
};