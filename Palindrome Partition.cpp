class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int len=s.size();
        if(len==0)
        {
            vector<string> temp;
            result.push_back(temp);
            return result;
        }
        int i,j;
        for(i=0;i<len;i++)
        {
            if(s[i]!=s[0]) continue;
            for(j=1;2*j<i;j++)
                if(s[j]!=s[i-j]) break;
            if(2*j>=i)
            {
                vector<vector<string>>temp=partition(s.substr(i+1,len-i-1));
                string first=s.substr(0,i+1);
                for(auto iter=temp.begin();iter!=temp.end();iter++)
                {
                    vector<string> t=*iter;
                    t.insert(t.begin(),first);
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};