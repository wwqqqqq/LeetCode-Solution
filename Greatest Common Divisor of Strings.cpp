class Solution {
public:
    int SmallestDivisor(string str) {
        for(int i = 0; i < str.size(); i++) {
            if(str.size() % (i + 1) != 0)
                continue;
            int len = i + 1;
            int j;
            for(j = i + 1; j < str.size(); j++) {
                int times = j / len;
                if(str[j] != str[j - len * times])
                    break;
            }
            if(j >= str.size())
                return len;
        }
        return str.size();
    }
    int gcd(int a, int b) {
        if(a == b)
            return a;
        if(a < b)
            return gcd(b, a);
        if(a % b == 0)
            return b;
        return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        int d1 = SmallestDivisor(str1);
        int d2 = SmallestDivisor(str2);
        if(d1 != d2)
            return "";
        for(int i = 0; i < d1; i++) {
            if(str1[i] != str2[i])
                return "";
        }
        // str1[0..d1] = str2[0..d2]
        int t1 = str1.size() / d1;
        int t2 = str2.size() / d2;
        // find highest common factor of t1 and t2
        int t = gcd(t1, t2);
        string result;
        string s = str1.substr(0, d1);
        for(int i = 0; i < t; i++)
            result.append(s);
        return result;
    }
};