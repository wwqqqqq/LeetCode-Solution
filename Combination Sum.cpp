class Solution {
public:
    void findCS(vector<int> candidates, int target, vector<vector<int>>& result)
    {
        if(candidates.size()==0) return;
        vector<vector<int>> temp;
        int x=candidates[candidates.size()-1];
        candidates.pop_back();
        int i=0;
        while(x*i<=target)
        {
            if(x*i==target)
            {
                vector<int> temp;
                for(int j=0;j<i;j++) temp.push_back(x);
                result.push_back(temp);
            }
            else
            {
                vector<vector<int>> temp;
                findCS(candidates,target-x*i,temp);
                for(auto iter=temp.begin();iter!=temp.end();iter++)
                {
                    for(int j=0;j<i;j++) (*iter).push_back(x);
                }
                result.insert(result.end(),temp.begin(),temp.end());
            }
            i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        findCS(candidates,target,result);
        return result;
    }
};