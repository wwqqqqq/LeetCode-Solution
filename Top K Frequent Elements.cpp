class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> Num;
        for(auto iter=nums.begin();iter!=nums.end();iter++)
        {
            if(Num.find(*iter)==Num.end()) Num.insert(pair<int,int>(*iter,1));
            else Num[*iter]++;
        }
        map<int,vector<int>> m;
        for(auto iter=Num.begin();iter!=Num.end();iter++)
        {
            if(m.find(iter->second)==m.end())
            {
                vector<int> temp;
                temp.push_back(iter->first);
                m.insert(pair<int,vector<int>>(iter->second,temp));
                //m.insert(pair<int,int>(iter->second,iter->first));
            }
            else m[iter->second].push_back(iter->first);
                //m[iter->second]=iter->first;
        }
        auto iter=m.end();
        vector<int> result;
        for(iter--;k>0;iter--)
        {
            vector<int> temp=iter->second;
            for(auto iter1=temp.begin();iter1!=temp.end()&&k>0;iter1++,k--)
                result.push_back(*iter1);
            /*return {(k-((iter->second).size()))<0};
            if(k-((iter->second).size())<0)
            {
                vector<int> temp=iter->second;
                for(auto iter1=temp.begin();k>0;iter1++,k--)
                    result.push_back(*iter1);
            }
            else 
            {
                result.insert(result.end(),(iter->second).begin(),(iter->second).end());
                k-=(iter->second).size();
            }*/
        }
        return result;
    }
};