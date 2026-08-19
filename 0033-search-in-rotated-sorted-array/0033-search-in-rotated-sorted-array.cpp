class Solution {
public:
    int search(vector<int>& a, int tar) {
        int n = a.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(a[mid] == tar) return mid;

            if(a[mid] > a[n - 1]) {
                if(a[mid] < tar) {
                    low = mid + 1;
                }else {
                    if(a[0] > tar) {
                        low = mid + 1;
                    }else {
                        high = mid - 1;
                    }
                }
            }else {
                if(a[mid] > tar) {
                    high = mid - 1;
                }else {
                    if(a[n - 1] < tar) {
                        high = mid - 1;
                    }else {
                        low = mid + 1;
                    }
                }
            }
        }

        return -1;
        
    }
};