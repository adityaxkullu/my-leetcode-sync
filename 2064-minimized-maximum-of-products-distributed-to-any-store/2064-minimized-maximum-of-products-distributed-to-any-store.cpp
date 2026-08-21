class Solution {
public:
    bool canDistribute(int n, vector<int> &a, int guess) {
        int m = a.size();
        int shops = 0;

        for(int i = 0; i < m; i++) {
            shops += (a[i] + guess - 1) / guess;

            if(shops > n) return false; 
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>&a) {
        int m = a.size();
        int low = 1, high = *max_element(a.begin(), a.end()), ans;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canDistribute(n, a, mid)) {
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return ans;
        
    }
};