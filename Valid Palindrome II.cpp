class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) {
                if(isPalindrome(s.substr(i+1,j-i)) || isPalindrome(s.substr(i, j-i)))
                    return true;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};