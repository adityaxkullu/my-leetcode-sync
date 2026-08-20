class Solution {
public:
    bool canDivide(vector<int> &a, int thold, int guessDiv) {
        int n = a.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += (a[i] + guessDiv - 1) / guessDiv;

            if(sum > thold) return false;
        }

        return true;
    }
    int smallestDivisor(vector<int>& a, int thold) {
        int n = a.size();
        int low = 1, high = -1, ans = -1;

        for(int i = 0; i < n; i++) {
            high = max(high, a[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(!canDivide(a, thold, mid)) {
                low = mid + 1;
            }else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
        
    }
};