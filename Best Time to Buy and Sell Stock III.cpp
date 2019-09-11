class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        vector<int> profit1(prices.size(), 0); // profit using 1 transaction
        vector<int> profit2(prices.size(), 0); // profit using 2 transactions
        for(int i = prices.size() - 2; i >= 0; i--) {
            // one transaction
            int max = profit1[i+1];
            int max2 = profit2[i+1];
            for(int j = i + 1; j < prices.size(); j++) {
                int t = prices[j] - prices[i];
                if(t > max) max = t;
                if(t > 0 && j + 1 < prices.size()) {
                    t += profit1[j+1];
                    if(t > max2) max2 = t;
                }
            }
            profit1[i] = max;
            profit2[i] = max2;
        }
        if(profit1[0] < profit2[0])
            return profit2[0];
        return profit1[0];
        
        /* SOLUTION WITHOUT ANY TRANSACTION AMOUNT LIMITS
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
        */
    }
};