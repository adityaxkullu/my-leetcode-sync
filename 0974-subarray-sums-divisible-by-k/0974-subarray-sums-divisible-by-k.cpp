class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0, res = 0; 
        unordered_map<int, int> f;
        f[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            int rem = sum % k;

            if(rem < 0) {
                rem = rem + k;
            }

            res += f[rem];
            f[rem]++;

        }

        return res;
        
    }
};