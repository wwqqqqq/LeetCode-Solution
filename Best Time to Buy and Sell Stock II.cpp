class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        // SOLUTION WITHOUT ANY TRANSACTION AMOUNT LIMITS
        vector<int> profit(prices.size(), 0);
        for(int i = prices.size() - 1; i >= 0; i--) {
            int max = 0;
            for(int j = i; j < prices.size(); j++) {
                int p = prices[j] - prices[i];
                if(p < 0)
                    p = 0;
                if(j < prices.size() -1)
                    p += profit[j+1];
                if(p > max) max = p;
            }
            profit[i] = max;
        }
        return profit[0];
    }
};