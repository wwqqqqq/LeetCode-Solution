class Solution {
public:
    string findCommonPrefix(string s1, string s2) {
        int i;
        for(i = 0; i < s1.size() && i < s2.size(); i++) {
            if(s1[i] != s2[i])
                break;
        }
        return s1.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){ 
            string empty;
            return empty;
        }
        string s = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            if(s.size() == 0)
                return s;
            s = findCommonPrefix(s, strs[i]);
        }
        return s;
    }
};