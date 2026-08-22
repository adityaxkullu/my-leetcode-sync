class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int low = *min_element(a.begin(), a.end());
        int high = *max_element(a.begin(), a.end());

        int res = low;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for(int x : a) {
                if(x >= mid) count++;
            }

            if(count >= k) {
                res = mid;
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }

        return res;
        
    }
};