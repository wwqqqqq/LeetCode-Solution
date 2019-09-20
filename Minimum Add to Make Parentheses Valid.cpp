class Solution {
public:
    int minAddToMakeValid(string S) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '(' && i + 1 < S.size() && S[i+1] == ')') {
                // find a '()' pair!
                string new_string = S.substr(0, i);
                new_string.append(S.substr(i+2));
                return minAddToMakeValid(new_string);
            }
        }
        return S.size();
    }
    /*map<string, int> result;
    int minAddToMakeValid(string S) {
        if(S.size() <= 1)
            return S.size();
        auto iter = result.find(S);
        if(iter != result.end())
            return iter->second;
        if(S[0] == ')' || S[S.size()-1] == '(') {
            int beg = 0;
            int end = S.size() - 1;
            for(int i = 0; i < S.size(); i++) {
                beg = i;
                if(S[i] == '(')
                    break;
            }
            for(int i = S.size() - 1; i >= 0; i--) {
                end = i;
                if(S[i] == ')')
                    break;
            }
            int t = S.size();
            if(beg < end)
                t = beg + S.size() - end - 1 + minAddToMakeValid(S.substr(beg, end-beg+1));
            result.insert(pair<string,int>(S,t));
            return t;
        }
        int min = S.size();
        int beg = 0;
        if(S[1] == ')') {
            int t = minAddToMakeValid(S.substr(2));
            result.insert(pair<string,int>(S,t));
            return t;
        }
        int end = -1;
        for(int i = beg + 1; i < S.size(); i++) {
            if(S[i] == ')' && S[i-1] != '(') {
                end = i;
                int t1 = minAddToMakeValid(S.substr(beg+1, end-beg-1));
                int temp = beg + t1 + minAddToMakeValid(S.substr(end+1));
                if(temp < min) min = temp;
                if(t1 == 0) {
                    result.insert(pair<string, int>(S, min));
                    return min;
                }
            }
        }
        int temp = beg + 1 + minAddToMakeValid(S.substr(beg+1));
        if(temp < min) min = temp;
        result.insert(pair<string, int>(S, min));
        return min;
    }*/
};