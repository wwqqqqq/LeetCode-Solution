class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')') {
                count--;
                if(count < 0)
                    return false;
            }
        }
        if(count != 0)
            return false;
        return true;
    }
    int delLeft(string s) {
        int count = 0;
        int result = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ')')
                count++;
            else if(s[i] == '(') {
                count--;
                if(count < 0) {
                    result++;
                    count++;
                }
            }
        }
        return result;
    }
    int delRight(string s) {
        int count = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')') {
                count--;
                if(count < 0) {
                    result++;
                    count++;
                }
            }
        }
        return result;
    }
    map<string, set<string>> m_r;
    map<string, set<string>> m_l;
    set<string> removeRightParentheses(string s) {
        if(s.size() == 0) {
            set<string> result;
            result.insert("");
            return result;
        }
        auto iter = m_r.find(s);
        if(m_r.end() != iter)
            return iter->second;
        vector<int> rightParentheseIndex;
        int count = 0;
        int i;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')') {
                count--;
                rightParentheseIndex.push_back(i);
            }
            if(count < 0)
                break;
        }
        set<string> result;
        if(count < 0) {
            // we should delete at least one right parenthesis before or at s[i];
            for(int j = 0; j < rightParentheseIndex.size(); j++) {
                int index = rightParentheseIndex[j];
                // delete rightParenthese at s[index]
                string t = s.substr(0, index);
                t.append(s.substr(index+1));
                auto temp = removeRightParentheses(t);
                result.insert(temp.begin(), temp.end());
            }
        }
        else {
            result.insert(s);
        }
        m_r.insert(pair<string,set<string>>(s,result));
        return result;
    }
    set<string> removeLeftParentheses(string s) {
        if(s.size() == 0) {
            set<string> result;
            result.insert("");
            return result;
        }
        auto iter = m_l.find(s);
        if(m_l.end() != iter)
            return iter->second;
        vector<int> leftParentheseIndex;
        int count = 0;
        int i;
        for(i = s.size()-1; i >= 0; i--) {
            if(s[i] == ')')
                count++;
            else if(s[i] == '(') {
                count--;
                leftParentheseIndex.push_back(i);
            }
            if(count < 0)
                break;
        }
        set<string> result;
        if(count < 0) {
            // we should delete at least one left parenthesis after or at s[i];
            for(int j = 0; j < leftParentheseIndex.size(); j++) {
                int index = leftParentheseIndex[j];
                // delete rightParenthese at s[index]
                string t = s.substr(0, index);
                t.append(s.substr(index+1));
                auto temp = removeLeftParentheses(t);
                result.insert(temp.begin(), temp.end());
            }
        }
        else {
            result.insert(s);
        }
        m_l.insert(pair<string,set<string>>(s,result));
        return result;
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> result_s;
        if(delLeft(s) == 0) {
            result_s = removeRightParentheses(s);
        }
        else if(delRight(s) == 0) {
            result_s = removeLeftParentheses(s);
        }
        else {
            set<string> t1 = removeRightParentheses(s);
            for(auto iter = t1.begin(); iter != t1.end(); iter++) {
                set<string> t2 = removeLeftParentheses(*iter);
                result_s.insert(t2.begin(), t2.end());
            }
        }
        vector<string> result;
        std::copy(result_s.begin(), result_s.end(), std::back_inserter(result));
        return result;
    }
};