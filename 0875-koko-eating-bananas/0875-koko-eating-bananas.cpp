class Solution {
public:
    long long totalTime(vector<int> &a, int speed) {
        int n = a.size();
        long long t = 0;

        for(int i = 0; i < n; i++) {
            t += a[i] / speed;

            if(a[i] % speed != 0) t++;
        }

        return t;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int low = 1, high = INT_MIN, ans;

        for(int i = 0; i < n; i++) {
            high = max(high, a[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long time = totalTime(a, mid);

            if(time > h) {
                low = mid + 1;
            }else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;    
    }
};