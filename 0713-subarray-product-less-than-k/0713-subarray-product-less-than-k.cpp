class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
       int n = a.size();
       int low = 0, count = 0;
       long long product = 1;

       if(k <= 1) {
        return 0;
       }

       for(int high = 0; high < n; high++) {
        product *= a[high];

        while(product >= k) {
            product /= a[low];
            low++;
        }

        count += (high - low + 1); 
       }

       return count;
        
    }
};