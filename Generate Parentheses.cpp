class Solution {
public:
    vector<string> generate(stack<char> &s, int n) {
        vector<string> result;
        if(n == 0) {
            string str;
            if(s.empty()) {
                result.push_back(str);
                return result;
            }
            str.append(s.size(), ')');
            result.push_back(str);
            return result;
        }
        s.push('(');
        vector<string> temp = generate(s, n-1);
        for(int i = 0; i < temp.size(); i++) {
            string str = "(";
            str.append(temp[i]);
            result.push_back(str);
        }
        s.pop();
        
        if(!s.empty()) {
            s.pop();
            vector<string> temp1 = generate(s, n);
            s.push('(');
            for(int i = 0; i < temp1.size(); i++) {
                string str = ")";
                str.append(temp1[i]);
                result.push_back(str);
            }
        }
        return result;
    }
    vector<string> generateParenthesis(int n) {
        stack<char> s;
        return generate(s, n);
    }
};