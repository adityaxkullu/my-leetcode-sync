class Solution {
public:
    bool canMake(vector<int> &a, int m, int k, int days) {
        int n = a.size();
        int flowers = 0, bouquets = 0;

        for(int i = 0; i < n; i++) {
           if(a[i] <= days) {
            flowers++;

            if(flowers == k) {
                bouquets++;
                flowers = 0;
            }

           }else {

            flowers = 0;

           }

           if (bouquets >= m) return true;
        }

        return false;
    }

    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();

        if((long long)m * k > n) return -1;

        int low = 1, high = 0, ans = -1;

        for(int i = 0; i < n;  i++) {
            high = max(high, a[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(!canMake(a, m, k, mid)) {
                low = mid + 1;
            }else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;    
    }
};