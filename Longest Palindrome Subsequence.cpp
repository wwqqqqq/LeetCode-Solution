class Solution {
public:
    int m[1000][1000];
    int longestPalindromeSubseq(string s) {
        if(s.size()<=1) return s.size();
        string t(s.size()+1,'\0');
        int i=0;
        for(i=0;i<s.size();i++) t[i]=s[s.size()-i-1];
        m[0][0]=(s[0]==t[0])?1:0;
        for(i=1;i<s.size();i++)
        {
            m[0][i]=(s[0]==t[i])?1:m[0][i-1];
            m[i][0]=(s[i]==t[0])?1:m[i-1][0];
        }
        for(i=1;i<s.size();i++)
        {
            for(int j=1;j<s.size();j++)
            {
                if(s[i]==t[j]) m[i][j]=m[i-1][j-1]+1;
                else m[i][j]=(m[i-1][j]>m[i][j-1])?m[i-1][j]:m[i][j-1];
            }
        }
        return m[s.size()-1][s.size()-1];
    }
};