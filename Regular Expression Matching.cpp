class Solution {
public:
    bool isMatch(string s, string p) {
        /*if(p.size() == 0 && s.size() == 0)
            return true;
        else if(p.size() == 0 || s.size() == 0)
            return false;*/
        
        for(int i = 0;; i++) {
            if(i < s.size() && i >= p.size())
                return false;
            if(i < p.size() && i >= s.size()) {
                if(p[i] == '*') {
                    return isMatch(s.substr(i), p.substr(i+1));
                }
                if(i+1 < p.size() && p[i+1] == '*') {
                    return isMatch(s.substr(i), p.substr(i+2));
                }
                else return false;
            }
            if(i >= p.size() && i >= s.size())
                break;
            if(i + 1 < p.size() && p[i+1] == '*') {
                if(isMatch(s.substr(i), p.substr(i+2)))
                    return true;
            }
            if(p[i] == '.' || p[i] == s[i]) {
                continue;
            }
            else if(p[i] == '*') {
                if(i == 0)
                    return false;
                if(p[i-1] == '.') {
                    if(i == p.size() - 1)
                        return true;
                    for(int j = i; j <= s.size(); j++)
                        if(isMatch(s.substr(j), p.substr(i+1)))
                            return true;
                    return false;
                }
                if(i + 1 == p.size()) {
                    for(int j = i; j < s.size(); j++)
                        if(s[j] != s[i-1])
                            return false;
                    return true;
                }
                for(int j = i; j < s.size(); j++) {
                    if(isMatch(s.substr(j), p.substr(i+1)))
                        return true;
                    if(s[i-1] != s[j])
                        return false;
                }
                return false;
                
            }
            else if(p[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
};