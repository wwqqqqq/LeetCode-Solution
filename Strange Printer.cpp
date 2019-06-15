class Solution {
public:
    vector<int> strSplit_beg(string s, char delimiter) {
        vector<int> begin;
        if(s.size() == 0)
            return begin;
        if(s[0] != delimiter)
            begin.push_back(0);
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != delimiter && s[i-1] == delimiter)
                begin.push_back(i);
        }
        return begin;
    }
    vector<int> strSplit_ed(string s, char delimiter) {
        vector<int> end;
        if(s.size() == 0)
            return end;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] != delimiter && s[i+1] == delimiter)
                end.push_back(i);
        }
        if(s[s.size()-1] != delimiter)
            end.push_back(s.size()-1);
        return end;
    }
    int strangePrinter(string s, vector<int> &begin, vector<int> &end, int ofst, char delimiter, map<string, int> &m1, map<int,int> &m2) {
        if(ofst >= begin.size())
            return 0;
        if(begin.size() - ofst == 1 && end[ofst]-begin[ofst]+1 != s.size())
            return strangePrinter(s.substr(begin[ofst], end[ofst]-begin[ofst]+1), m1);
        auto iter = m2.find(ofst);
        if(iter != m2.end())
            return iter->second;
        int min = 1000;
        for(int i = ofst; i < begin.size(); i++) {
            string t = s.substr(begin[ofst], end[i]-begin[ofst]+1);
            if(t.size() == s.size())
                 break;
            int sum = strangePrinter(s, begin, end, i+1, delimiter, m1, m2);
            if(sum >= min) continue;
            sum += strangePrinter(t, m1);
            if(sum < min) min = sum;
        }
        /*string s = pieces[beg];
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
        }*/
        m2.insert(pair<int,int>(ofst, min));
        return min;
    }
    /*vector<string> strSplit(string s, char delimiter) {
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
    }*/
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
            //vector<string> strs = strSplit(s, c);
            vector<int> begin = strSplit_beg(s, c);
            vector<int> end = strSplit_ed(s, c);
            map<int,int> m2;
            sum += strangePrinter(s, begin, end, 0, c, m, m2);
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