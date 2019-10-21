class Solution {
public:
    map<string,int> m;
    bool valid(string s) {
        int num = stoi(s);
        if(num <= 26 && num >= 1)
            return true;
        return false;
    }
    int numDecodings(string s) {
        if(s.size() == 0)
            return 1;
        if(s[0] == '0')
            return 0;
        auto iter = m.find(s);
        if(iter != m.end())
            return iter->second;
        int result = numDecodings(s.substr(1));
        if(s.size() >= 2 && valid(s.substr(0,2))) {
            result += numDecodings(s.substr(2));
        }
        m.insert(pair<string,int>(s,result));
        return result;
    }
};