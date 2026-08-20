class Solution {
public:
    bool canShipToday(vector<int> &a, int days, int guessCap) {
        int n = a.size();

        int d = 1;
        int weight = 0;

        for(int i = 0; i < n; i++) {
            if(weight + a[i] <= guessCap) {
                weight += a[i];
                continue;
            }else {
                d++;
                weight = a[i];
                if(d > days) return false;
            }
        }

        return true;
    }
    int shipWithinDays(vector<int>& a, int days) {
        int n = a.size();
        int low = 0, ans = -1;
        int high = 0;

        for(int i = 0; i < n; i++) {
            low = max(low, a[i]);
            high += a[i];
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(!canShipToday(a, days, mid)) {
                low = mid + 1;
            }else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
        
    }
};