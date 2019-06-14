// 有一种情况没有考虑到，即后打印上的文字可以覆盖先前的有效文字
// 只要之后再重新打印上被覆盖的文字，还是有可能做到打印次数最小
// 如字符串"tabtbat"，先打印"ttttttt"，使用a覆盖 "taaaaat"，使用b覆盖 "tabbbat"，再补上中间的t，只需要4步。
// 但以我的算法得到的结果确需要5步。
class Solution {
public:
    vector<string> strSplit(string s, char delimiter) {
        int i;
        for(i = 0; i < s.size(); i++)
            if(s[i] != delimiter)
                break;
        if(i == s.size()) {
            vector<string> empty;
            return empty;
        }
        int beg = i;
        for(i = i + 1; i < s.size(); i++)
            if(s[i] == delimiter)
                break;
        if(i == s.size()) {
            vector<string> result = {s.substr(beg, i - beg)};
            return result;
        }
        vector<string> result = strSplit(s.substr(i), delimiter);
        result.push_back(s.substr(beg, i - beg));
        return result;
    }
    int strangePrinter(string s, map<string, int> &m) {
        if(s.size() == 1) return 1;
        if(s.size() == 0) return 0;
        auto iter_m = m.find(s);
        if(iter_m != m.end())
            return iter_m->second;
        set<char> letters;
        for(int i = 0; i < s.size(); i++) {
            letters.insert(s[i]);
        }
        if(letters.size() == 1)
            return 1;
        if(letters.size() == s.size())
            return letters.size();
        int min = s.size();
        for(auto iter = letters.begin(); iter != letters.end(); iter++) {
            char c = *iter;
            int sum = 1;
            vector<string> strs = strSplit(s, c);
            for(int i = 0; i < strs.size(); i++) {
                sum += strangePrinter(strs[i], m);
                if(sum >= min)
                    break;
            }
            if(sum < min) min = sum;
        }
        m.insert(pair<string, int>(s, min));
        return min;
    }
    int strangePrinter(string s) {
        map<string, int> m;
        return strangePrinter(s, m);
    }
};