class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> temp;
        char last='\0';
        int begin=-1;
        int max=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==last)
            {
                if(temp.size()>max) max=temp.size();
                temp.clear();
                last=s[i];
                begin=i;
                temp.insert(s[i]);
            }
            else
            {
                if(temp.find(s[i])==temp.end())
                {
                    last=s[i];
                    temp.insert(s[i]);
                }
                else
                {
                    if(temp.size()>max) max=temp.size();
                    int j;
                    for(j=begin;j<i;j++)
                    {
                        if(s[j]==s[i]) break;
                        temp.erase(s[j]);
                    }
                    //temp.clear();
                    begin=(j+1>i)?i:j+1;
                    last=s[i];
                    //temp.insert(s[i]);
                }
            }
        }
        if(temp.size()>max) max=temp.size();
        return max;
    }
};