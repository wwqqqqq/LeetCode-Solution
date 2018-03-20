class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> m;
        stack<int> s;
        vector<int> res;
        for(auto iter = nums.begin();iter<nums.end(); iter++)
        {
            while(!s.empty() && s.top() < *iter)
            {
                m[s.top()] = *iter;
                s.pop();
            }
            s.push(*iter);
        }
        while(!s.empty())
        {
            m[s.top()] = -1;
            s.pop();
        }
        for(auto iter = findNums.begin(); iter<findNums.end(); iter++)
            res.push_back(m[*iter]);
        return res;
    }
};