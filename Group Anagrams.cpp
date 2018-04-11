class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char,int>> m;
        vector<vector<string>> result;
        int count=0,i;
        for(auto iter=strs.begin();iter!=strs.end();iter++)
        {
            string str=*iter;
            map<char,int> temp;
            for(i=0;i<str.size();i++)
            {
                if(temp.find(str[i])==temp.end())
                {
                    temp.insert(pair<char,int>(str[i],1));
                }
                else temp[str[i]]++;
            }
            for(i=0;i<count;i++)
            {
                if(temp.size()!=(m[i]).size()) continue;
                auto iter1=temp.begin(),iter2=m[i].begin();
                for(;iter1!=temp.end();iter1++,iter2++)
                {
                    if(iter1->first!=iter2->first||iter1->second!=iter2->second) break;
                }
                if(iter1==temp.end())
                {
                    result[i].push_back(str);
                    break;
                }
            }
            if(i==count)
            {
                m.push_back(temp);
                vector<string> t;
                t.push_back(str);
                result.push_back(t);
                count++;
            }
        }
        return result;
    }
};