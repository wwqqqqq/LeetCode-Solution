class Solution {
public:
    string func(string num, int k) {
        if(num.size() == k)
            return num;
        if(k == 0)
            return "";
        int min_ind = 0;
        char min = num[0];
        for(int i = 0; i <= num.size() - k; i++) {
            if(num[i] < min) {
                min = num[i];
                min_ind = i;
                if(min == 0)
                    break;
            }
        }
        if(min_ind == num.size() - k)
            return num.substr(min_ind);
        string result;
        result.append(1, min);
        result.append(func(num.substr(min_ind+1), k-1));
        return result;
    }
    string removeKdigits(string num, int k) {
        k = num.size() - k;
        string result = func(num, k);
        int beg = 0;
        for(; beg < result.size(); beg++) {
            if(result[beg] != '0')
                break;
        }
        if(beg == result.size())
            return "0";
        return result.substr(beg);
    }
};