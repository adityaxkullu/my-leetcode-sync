class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0, res = 0;
        unordered_map<int, int> f;
        f[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            int quest = sum - k;
            int freq = f[quest];
            res += freq;
            f[sum]++;
        }

        return res;

        
      
    }
};