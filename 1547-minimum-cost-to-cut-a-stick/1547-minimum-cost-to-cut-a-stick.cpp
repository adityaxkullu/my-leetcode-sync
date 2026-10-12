class Solution {
public:
    int minCost(int n, vector<int>& c) {
        vector<int> cuts;

        cuts.push_back(0);

        for(int i = 0; i < c.size(); i++) {
            cuts.push_back(c[i]);
        }

        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int s = cuts.size();

        vector<vector<int>> dp(s, vector<int>(s, 0));

        for(int i = s - 2; i >= 1; i--) {
            for(int j = i; j <= s - 2; j++) {
                int res = INT_MAX;

                for(int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1];

                    int r = cost + dp[i][k - 1] + dp[k + 1][j];

                    res = min(res, r);
                }

                dp[i][j] = res;
            }
        } 

        return dp[1][s - 2];  
    }
};