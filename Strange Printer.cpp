class Solution {
public:
    int strangePrinter(string s, set<char> &letters, map<string, int> &m) {
        auto iter_m = m.find(s);
        if(iter_m != m.end())
            return iter_m->second;
        int min = s.size();
        if(min == 1)
            return 1;
        for(auto iter = letters.begin(); iter != letters.end(); iter++) {
            char c = *iter;
            int i = 0;
            for(; i < s.size(); i++)
                if(s[i] == c)
                    break;
            if(i == s.size())
                continue;
            int beg = i + 1;
            int sum = 1;
            letters.erase(c);
            sum += strangePrinter(s.substr(0, i), letters, m);
            bool equaltoc = true;
            for(; i < s.size(); i++) {
                if(equaltoc && s[i] != c) {
                    beg = i;
                    equaltoc = false;
                }
                else if(!equaltoc && s[i] == c) {
                    sum += strangePrinter(s.substr(beg, i - beg), letters, m);
                    if(sum >= min) break;
                    equaltoc = true;
                }
            }
            if(sum >= min) continue;
            if(!equaltoc)
                sum += strangePrinter(s.substr(beg), letters, m);
            letters.insert(c);
            if(sum < min) min = sum;
        }
        m.insert(pair<string, int>(s, min));
        return min;
    }
    int strangePrinter(string s) {
        set<char> letters;
        map<string, int> m;
        for(int i = 0; i < s.size(); i++)
            letters.insert(s[i]);
        return strangePrinter(s, letters, m);
    }
};