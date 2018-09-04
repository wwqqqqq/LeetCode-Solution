class Solution {
public:
    string longestSubString(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1==0 || l2==0)
            return "";
        int mat[l1][l2];
        int max = 0;
        int mi = 0, mj = 0;
        for(int i=0;i<l1;i++) {
            mat[i][0] = s1[i]==s2[0]?1:0;
            if(s1[i]==s2[0] && max==0) {
                max = 1;
                mi = i;
                mj = 0;
            }
        }
        for(int i=1;i<l2;i++) {
            mat[0][i] = s1[0]==s2[i]?1:0;
            if(s1[0]==s2[i] && max==0) {
                max = 1;
                mi = 0;
                mj = i;
            }
        }
        for(int i=1;i<l1;i++) {
            for(int j=1;j<l2;j++) {
                if(s1[i]==s2[j]) {
                    mat[i][j] = mat[i-1][j-1] + 1;
                    if(mat[i][j]>max) {
                        max = mat[i][j];
                        mi = i;
                        mj = j;
                    }
                }
                else
                    mat[i][j] = 0;
            }
        }
        if(max==0)
            return "";
        return s1.substr(mi-max+1,max);
    }
    int isPalindrome(string& s, int beg, int ed) {
        //int beg = 0;
        //int ed = s.size() - 1;
        while(beg<=ed) {
            if(s[beg]!=s[ed])
                return 0;
            beg++;
            ed--;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        //string t = s;
        //reverse(t.begin(),t.end());
        //return longestSubString(s, t);
        int len = s.size();
        while(len>0) {
            for(int i=0;i+len-1<s.size();i++) {
                if(s[i]!=s[i+len-1])
                    continue;
                if(isPalindrome(s, i, i+len-1)) {
                    string t = s.substr(i,len);
                    return t;
                }
            }
            len--;
        }
        return "";
    }
};