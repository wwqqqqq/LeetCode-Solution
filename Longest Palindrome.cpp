class Solution {
public:
    int m[52];
    int longestPalindrome(string s) {
        int i;
        for(i=0;i<52;i++) m[i]=0;
        for(i=0;i<s.size();i++)
            if(s[i]>='a'&&s[i]<='z') m[s[i]-'a']++;
            else m[s[i]-'A'+26]++;
        int count=0;
        bool single=false;
        for(i=0;i<52;i++)
        {
            if(m[i]%2) single=true;
            count+=m[i]-m[i]%2;
        }
        if(single) return count+1;
        else return count;
    }
};