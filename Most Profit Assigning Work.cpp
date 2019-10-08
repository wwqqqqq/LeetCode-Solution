class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int result = 0;
        // sort worker and difficulty
        sort(worker.begin(), worker.end());
        map<int,int> job;
        for(int i = 0; i < difficulty.size(); i++) {
            auto iter = job.find(difficulty[i]);
            if(iter == job.end())
                job.insert(pair<int,int>(difficulty[i], profit[i]));
            else if(profit[i] > iter->second)
                iter->second = profit[i];
        }
        int prev = 0;
        auto iter = job.begin();
        for(int i = 0; i < worker.size(); i++) {
            int max_profit = prev;
            while(iter != job.end()) {
                if(iter->first > worker[i])
                    break;
                if(iter->second > max_profit)
                    max_profit = iter->second;
                iter++;
            }
            result += max_profit;
            prev = max_profit;
        }
        return result;
    }
};