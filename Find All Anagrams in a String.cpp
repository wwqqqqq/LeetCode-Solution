class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        vector<int> result;
        int i;
        map<char,int> m;
        for(i=0;p[i]!='\0';i++)
        {
            if(m.find(p[i])==m.end())
                m.insert(pair<char,int>(p[i],1));
            else m[p[i]]+=1;
        }
        bool last=false;
        for(i=0;i<=lens-lenp;i++)
        {
            if(last==true)
            {
                if(s[i-1]==s[i+lenp-1]) 
                {
                    result.push_back(i);
                    continue;
                }
                else last=false;
            }
            auto temp=m;
            int j;
            for(j=0;j<lenp;j++)
            {
                if(temp.find(s[i+j])==temp.end()) break;
                temp[s[i+j]]-=1;
            }
            if(j<lenp)
            {
                i+=j;
                continue;
            }
            auto iter=temp.begin();
            for(;iter!=temp.end();iter++)
            {
                if(iter->second!=0) break;
            }
            if(iter==temp.end()) 
            {
                result.push_back(i);
                last=true;
            }
        }
        return result;
    }
};