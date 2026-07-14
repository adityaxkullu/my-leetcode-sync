class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();

        int maxProfit = 0, bestBuy = price[0];

        for(int i = 1; i < n; i++) {
            int sellPrice = price[i];
            int profit = sellPrice - bestBuy;

            if(price[i] < bestBuy) {
                bestBuy = price[i];
            }

            maxProfit = max(maxProfit, profit);
        } 

        if(maxProfit < 0) return 0;

        return maxProfit;



        
    }
};