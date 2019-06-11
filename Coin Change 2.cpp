class Solution {
public:
    int sortedchange(int amount, vector<int>& coins) {
        int count = 0;
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        int coin = coins[coins.size()-1];
        if(coins.size() == 1) {
            if(amount % coin == 0)
                return 1;
            else return 0;
        }
        coins.erase(coins.end()-1);
        int num = amount / coin;
        while(num >= 0) {
            count += sortedchange(amount - num * coin, coins);
            num--;
        }
        coins.push_back(coin);
        return count;
    }
    int change(int amount, vector<int>& coins) {
        vector<int> results(amount+1, 0);
        results[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            if(coin == 0)
                continue;
            for(int j = amount; j >= 0; j--) {
                if(results[j] == 0)
                    continue;
                for(int num = 1; num * coin + j <= amount; num++) {
                    results[j + num * coin] = results[j+num*coin] + results[j];
                }
            }
        }
        return results[amount];
        //sort(coins.begin(), coins.end());
        //return sortedchange(amount, coins);
    }
};