class Solution {
public:
    vector<vector<int>> findCS(map<int,int>& count, int target) {
        vector<vector<int>> result;
        if(count.size() == 0 && target != 0)
            return result;
        
        if(target == 0 || count.size() == 0) {
            vector<int> temp;
            result.push_back(temp);
            return result;
        }
        auto iter = count.end();
        iter--;
        int x = iter->first;
        int c = iter->second;
        int i;
        count.erase(iter);
        if(x > target) {
            result = findCS(count, target);
            count.insert(pair<int,int>(x,c));
            return result;
        }
        // sets that have x
        for(int i = 1; i <= c; i++) {
            if(i * x > target)
                break;
            vector<vector<int>> r1 = findCS(count, target - i * x);
            vector<int> t(i, x);
            for(int j = 0; j < r1.size(); j++) {
                r1[j].insert(r1[j].end(), t.begin(), t.end());
            }
            result.insert(result.end(), r1.begin(), r1.end());
        }
        // sets that don't have x
        vector<vector<int>> r2 = findCS(count, target);
        result.insert(result.end(), r2.begin(), r2.end());
        count.insert(pair<int,int>(x,c));
        return result;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        map<int,int> count;
        for(int i = 0; i < candidates.size(); i++) {
            int n = candidates[i];
            auto iter = count.find(n);
            if(iter != count.end())
                iter->second++;
            else count.insert(pair<int,int>(n, 1));
        }
        return findCS(count, target);
    }
};