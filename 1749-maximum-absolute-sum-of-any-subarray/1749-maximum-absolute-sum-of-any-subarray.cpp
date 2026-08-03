class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n = a.size();
        int maxEnd = a[0], minEnd = a[0], ans = abs(a[0]);

        for(int i = 1; i < n; i++) {
            maxEnd = max((maxEnd + a[i]), a[i]);
            minEnd = min((minEnd + a[i]), a[i]);

            ans = max(ans, max(maxEnd, abs(minEnd)));
            
        }

        return ans;

        
    }
};