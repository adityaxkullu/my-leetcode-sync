class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while(l < r) {
            lmax = max(lmax, h[l]);
            rmax = max(rmax, h[r]);

            if(lmax < rmax) {
                ans += lmax - h[l];
                l++;
            }else {
                ans += rmax - h[r];
                r--;
            }
        }

        return ans;
       
    }
};