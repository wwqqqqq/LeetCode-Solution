class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> res;
        int min=-1;
        for(auto iter = nums.begin();iter<nums.end();iter++)
        {
            res.insert(pair<int,int>(*iter, -1));
            if(*iter<min) min=*iter;
        }
        for(auto iter = nums.begin();iter<nums.end();iter++)
        {
            for(auto iter1 = nums.begin(); iter1<iter; iter1++)
            {
                if(res.find(*iter1)!=res.end() && res[*iter1]==-1 && *iter>*iter1)
                    res[*iter1] = *iter;
            }
        }
        vector<int> result;
        for(auto iter = findNums.begin();iter<findNums.end();iter++)
        {
            result.push_back(res[*iter]);
        }
        return result;
    }
};