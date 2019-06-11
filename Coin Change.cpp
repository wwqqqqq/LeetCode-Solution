class Solution {
public:
    int sortedCoinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 && amount != 0)
            return -1;
        if(amount == 0)
            return 0;
        int coin = coins[coins.size()-1];
        coins.erase(coins.end()-1);
        int num = amount / coin;
        if(amount % coin == 0) {
            coins.push_back(coin);
            return num;
        }
        int result = amount+1;
        while(num >= 0) {
            int count = sortedCoinChange(coins, amount - num * coin);
            if(count != -1) {
                //coins.push_back(coin);
                //return num + count;
                if(count + num < result)
                    result = count + num;
            }
            num--;
        }
        coins.push_back(coin);
        if(result == amount + 1)
            return -1;
        return result;
    }
    int coinChange(vector<int>& coins, int amount) {
        // 设置一个数组results, results[i]表示当amount为i时的结果
        vector<int> results(amount+1, amount+1);
        results[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                if(coin > i)
                    continue;
                if(coin == i) {
                    results[i] = 1;
                    break;
                }
                int num = results[i-coin] + 1;
                if(num < results[i])
                    results[i] = num;
            }
        }
        if(results[amount] == amount + 1)
            return -1;
        return results[amount];
        /*sort(coins.begin(), coins.end());
        return sortedCoinChange(coins, amount);*/
    }
};