class Solution {
public:
    string removeDuplicateLetters(string s) {
        int exist[26];
        char result[1000];
        int i,j,k=0;
        int len=s.size();
        if(len==0)
            return "\0";
        int remove[len];
        for(i=0;i<26;i++)
            exist[i]=0;
        for(i=0;s[i]!='\0';i++)
            exist[s[i]-'a']++;
        for(i=0;i<len;i++)
        {
            if(exist[s[i]-'a']==1)
                remove[i]=1;
            else
                remove[i]=0;
        }
        int pos=0;
        int st=0;
        for(st=0;st<len;st++)
        {
            if(remove[st]==2)
                continue;
            pos=st;
            
            for(i=st;i<len;i++)
            {
                if(remove[i]==2)
                    continue;
                if(s[i]<s[pos]) pos=i;
                exist[s[i]-'a']--;
                if(exist[s[i]-'a']==0) break;
            }
            for(i=0;i<26;i++)
                exist[i]=0;
            for(i=st;s[i]!='\0';i++)
                if(remove[i]!=2)
                    exist[s[i]-'a']++;
                i=st;
                if(i==pos)
                {
                    for(j=i;j<len;j++)
                        if(s[j]==s[i])
                            remove[j]=2;
                    result[k]=s[i];
                    k++;
                }
                else if(exist[s[i]-'a']==1)
                {
                    remove[i]=2;
                    result[k]=s[i];
                    k++;
                    
                }
                else
                {
                    remove[i]=2;
                    exist[s[i]-'a']--;
                }
            
        }
        result[k]='\0';
        return result;
    }
};
