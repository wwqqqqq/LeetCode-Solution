class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        set<string> s;
        int len=pattern.size();
        int last=0;
        vector<string> strs;
        for(int i=1;i<str.size();i++)
        {
            if(str[i]!=' '&&str[i]!='\0') continue;
            strs.push_back(str.substr(last,i-last));
            i++;
            last=i;
        }
        if(last!=str.size()) strs.push_back(str.substr(last,str.size()-last));
        if(len!=strs.size()) return false;
        for(int i=0;i<len;i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(strs[i]!=m[pattern[i]]) return false;
            }
            else
            {
                if(s.find(strs[i])!=s.end()) return false;
                m.insert(pair<char,string>(pattern[i],strs[i]));
                s.insert(strs[i]);
            }
        }
        return true;
    }
};