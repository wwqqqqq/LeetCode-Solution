class Solution {
public:
    stack<char> typedString(string s) {
        stack<char> result;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='#') {
                if(!result.empty())
                    result.pop();
            }
            else
                result.push(s[i]);
        }
        return result;
    }
    bool backspaceCompare(string S, string T) {
        stack<char> s1 = typedString(S);
        stack<char> s2 = typedString(T);
        if(s1.size()!=s2.size())
            return false;
        while(!s1.empty()) {
            if(s1.top()!=s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};