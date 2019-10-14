class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            while(i < j) {
                if(s[i] <= 'z' && s[i] >= 'a' || s[i] <= '9' && s[i] >= '0')
                    break;
                else if(s[i] <= 'Z' && s[i] >= 'A') {
                    s[i] = s[i] - 'A' + 'a';
                    break;
                }
                else i++;
            }
            while(i < j) {
                if(s[j] <= 'z' && s[j] >= 'a' || s[j] <= '9' && s[j] >= '0')
                    break;
                else if(s[j] <= 'Z' && s[j] >= 'A') {
                    s[j] = s[j] - 'A' + 'a';
                    break;
                }
                else j--;
            }
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};