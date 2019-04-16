class Solution {
public:
    pair<int, int> extractComponent(string s) {
        pair<int,int> result;
        result.first = 0; result.second = 0;
        int i;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == '+')
                break;
        }
        if(i >= s.size())
            return result;
        result.first = atoi(s.substr(0, i).c_str());
        result.second = atoi(s.substr(i+1).c_str());
        return result;
    }
    string complexNumberMultiply(string a, string b) {
        pair<int,int> a_ = extractComponent(a);
        pair<int,int> b_ = extractComponent(b);
        int real = a_.first * b_.first - a_.second * b_.second;
        int img = a_.first * b_.second + a_.second * b_.first;
        string result = to_string(real);
        result.append("+");
        result.append(to_string(img));
        result.append("i");
        return result;
    }
};