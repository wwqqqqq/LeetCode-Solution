class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        //if(K<=0||S.size()==0) return "";
        int i,j,k, count=0;
        for(i=0;S[i]!='\0';i++)
            if(S[i]=='-') count++;
            else if(S[i]>='a'&&S[i]<='z') S[i] = S[i]-'a'+'A';
        count = S.size()-count;
        string result(count+count/K+1,'\0');
        i = 0; k=0;j=0;
        int first=count%K;
        while(i<count)
        {
            if(first!=0)
            {
                for(k=0;k<first;k++)
                {
                    while(S[j]=='-') j++;
                    result[k]=S[j];
                    i++;j++;
                }
                if(i!=count)
                    result[k++]='-';
                first=0;
            }
            else
            {
                int temp=k;
                for(;k<K+temp;k++)
                {
                    while(S[j]=='-') j++;
                    result[k]=S[j];
                    i++;j++;
                }
                if(i!=count)
                    result[k++] = '-';
            }
        }
        return result;
    }
};