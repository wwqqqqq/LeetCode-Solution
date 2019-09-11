class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        vector<int> profit(prices.size(), 0);
        for(int i = prices.size() - 2; i >= 0; i--) {
            int max = profit[i+1];
            for(int j = i + 1; j < prices.size(); j++) {
                int t = prices[j] - prices[i];
                if(t > max) max = t;
            }
            profit[i] = max;
        }
        return profit[0];
    }
};