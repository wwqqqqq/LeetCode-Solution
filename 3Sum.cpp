class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> pos;
        map<int,int> neg;
        int count_zero=0;
        vector<vector<int>> result;
        for(auto iter=nums.begin();iter!=nums.end();iter++)
        { 
            if(*iter==0) count_zero++;
            else if(*iter>0)
            {
                if(pos.find(*iter)==pos.end()) pos.insert(pair<int,int>(*iter,1));
                else pos[*iter]++;
            }
            else
            {
                if(neg.find(-*iter)==neg.end()) neg.insert(pair<int,int>(-*iter,1));
                else neg[-*iter]++;
            }
        }
        if(count_zero>=3)
        {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            result.push_back(temp);
        }
        
        if(count_zero>0)
        {
            auto iter1=pos.begin();
            auto iter2=neg.begin();
            for(;iter1!=pos.end()&&iter2!=neg.end();)
            {
                if(iter1->first==iter2->first)
                {
                    vector<int> temp;
                    temp.push_back(-(iter2->first));
                    temp.push_back(0);
                    temp.push_back(iter1->first);
                    result.push_back(temp);
                    iter1++;
                    iter2++;
                }
                else if(iter1->first<iter2->first) iter1++;
                else iter2++;
            }
        }
        auto i=pos.begin();
        auto j=pos.begin();
        auto k=neg.begin();
        for(;i!=pos.end();i++)
        {
            int n=i->first;
            k=neg.begin();
            if(i->second>1) j=i;
            else {j=i;j++;}
            for(;j!=pos.end()&&k!=neg.end();)
            {
                if(j->first+n==k->first)
                {
                    vector<int> temp;
                    temp.push_back(-(k->first));
                    temp.push_back(n);
                    temp.push_back(j->first);
                    result.push_back(temp);
                    k++;j++;
                }
                else if(j->first+n<k->first) j++;
                else k++;
            }
        }
        i=neg.begin();
        for(;i!=neg.end();i++)
        {
            int n=i->first;
            k=pos.begin();
            if(i->second>1) j=i;
            else {j=i;j++;}
            for(;j!=neg.end()&&k!=pos.end();)
            {
                if(j->first+n==k->first)
                {
                    vector<int> temp;
                    temp.push_back(-(j->first));
                    temp.push_back(-n);
                    temp.push_back(k->first);
                    result.push_back(temp);
                    k++;j++;
                }
                else if(j->first+n<k->first) j++;
                else k++;
            }
        }
        return result;
    }
};