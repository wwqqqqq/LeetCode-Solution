class Solution {
public:
    string reverse(string s) {
        for(int i = 0; s.size() > i + i + 1; i++) {
            char t = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = t;
        }
        return s;
    }
    string reverseParentheses(string s) {
        if(s.size() <= 1)
            return s;
        int beg = -1;
        int end = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                beg = i;
            else if(s[i] == ')') {
                end = i;
                break;
            }
        }
        if(beg == -1 || end == -1)
            return s;
        string new_str;
        if(beg > 0)
            new_str.append(s.substr(0, beg));
        if(beg + 1 < end)
            new_str.append(reverse(s.substr(beg+1, end-1 - beg)));
        if(end < s.size()-1)
            new_str.append(s.substr(end+1));
        return reverseParentheses(new_str);
    }
};