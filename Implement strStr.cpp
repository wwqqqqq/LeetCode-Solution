class Solution {
public:
    int strStr(string haystack, string needle) {
        //violent solution
        int len1=haystack.size();
        int len2=needle.size();
        int i,j;
        for(i=0;i+len2<=len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j==len2) return i;
        }
        return -1;
    }
};