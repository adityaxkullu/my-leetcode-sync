class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i = 1; i < n; i++) {
            int profit = prices[i] - prices[i - 1];

            if(profit > 0) {
                maxProfit += profit;
            }
        }

        return maxProfit;
    }
};