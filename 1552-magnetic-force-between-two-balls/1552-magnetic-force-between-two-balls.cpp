class Solution {
public:
    bool canPlace(vector<int> &a, int m, int guess) {
        int n = a.size();
        int pos = a[0];
        int balls = 1;

        for(int i = 1; i < n; i++) {
            if(a[i] - pos >= guess) {
                balls++;
                pos = a[i];
            }else {
                continue;
            }
        }

        if(balls < m) return false;

        return true;
    }

    int maxDistance(vector<int>& a, int m) {
        int n = a.size();
        sort(a.begin(), a.end());
        int low = 1, high, amax = -1, amin = INT_MAX, ans = -1;

        for(int i = 0; i < n; i++) {
            amax = max(amax, a[i]);
            amin = min(amin, a[i]);

            high = amax - amin;
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(!canPlace(a, m, mid)) {
                high = mid - 1;
            }else {
                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
        
    }
};