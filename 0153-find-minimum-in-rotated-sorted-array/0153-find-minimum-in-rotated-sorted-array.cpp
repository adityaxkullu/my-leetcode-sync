class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(a[mid] > a[high]) {
                low = mid + 1;
            }else {
                high = mid;
                
            }
        } 

        return a[high];
        
    }
};