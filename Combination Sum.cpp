class Solution {
public:
    vector<vector<int>> result;
    void combinationSum(vector<int>& candidates, int begin, int target, vector<int> prefix) {
        if(target == 0) {
            result.push_back(prefix);
            return;
        }
        if(begin >= candidates.size()) {
            return;
        }
        int num = 0;
        while(num <= target) {
            combinationSum(candidates, begin + 1, target - num, prefix);
            num += candidates[begin];
            prefix.push_back(candidates[begin]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> prefix;
        combinationSum(candidates, 0, target, prefix);
        return result;
    }
};