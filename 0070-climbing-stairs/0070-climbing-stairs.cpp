class Solution {
public:
    unordered_map<int, int> dp;
    int fun(int i, int n) {
        if(i == n) return 1;
        if(i > n) return 0;

        if(dp.find(i) != dp.end()) return dp[i];
        
        int a1 = fun(i + 1, n);
        int a2 = fun(i + 2, n);

        dp[i] = a1 + a2;

        return a1 + a2;
    }
    int climbStairs(int n) {
        return fun(0, n);    
    }
};