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
    int strangePrinter(vector<string> &pieces, int beg, char delimiter, map<string, int> &m1, map<int,int> &m2, bool all) {
        if(beg >= pieces.size())
            return 0;
        if(pieces.size() - beg == 1)
            return strangePrinter(pieces[beg], m1);
        auto iter = m2.find(beg);
        if(iter != m2.end())
            return iter->second;
        string s = pieces[beg];
        int min = strangePrinter(s, m1) + strangePrinter(pieces, beg + 1, delimiter, m1, m2, true);
        int ed = pieces.size();
        if(beg == 0 && !all)
            ed = pieces.size() - 1;
        for(int i = beg + 1; i < ed; i++) {
            s.append(1, delimiter);
            s.append(pieces[i]);
            int result = strangePrinter(s, m1);
            if(result >= min) continue;
            result += strangePrinter(pieces, i+1, delimiter, m1, m2, true);
            if(result < min) min = result;
        }
        m2.insert(pair<int,int>(beg, min));
        return min;
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
            map<int,int> m2;
            bool all = false;
            if(s[0] == c || s[s.size()-1] == c)
                all = true;
            sum += strangePrinter(strs, 0, c, m, m2, all);
            m2.erase(m2.begin(), m2.end());
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