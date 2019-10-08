class Solution {
public:
    double soupServings(int A, int B, map<pair<int,int>, double>& m) {
        if(A <= 0 && B <= 0)
            return 0.5;
        if(A <= 0 && B > 0)
            return 1;
        else if(B <= 0)
            return 0;
        pair<int,int> key(A, B);
        auto iter = m.find(key);
        if(iter != m.end())
            return iter->second;
        double result = (soupServings(A-100,B,m) +
                         soupServings(A-75,B-25,m) +
                         soupServings(A-50,B-50,m) +
                         soupServings(A-25,B-75,m)) * 0.25;
        m.insert(pair<pair<int,int>,double>(key,result));
        return result;
    }
    /*double soupServings1(int A, int B, map<pair<int,int>, double>& m) {
        if(A <= 0 && B > 0)
            return 1;
        else if(B <= 0)
            return 0;
        pair<int,int> key(A, B);
        auto iter = m.find(key);
        if(iter != m.end())
            return iter->second;
        double result = (soupServings1(A-100,B,m) +
                         soupServings1(A-75,B-25,m) +
                         soupServings1(A-50,B-50,m) +
                         soupServings1(A-25,B-75,m)) * 0.25;
        m.insert(pair<pair<int,int>,double>(key,result));
        return result;
    }
    double soupServings2(int A, int B, map<pair<int,int>, double>& m) {
        if(A <= 0 && B <= 0)
            return 1;
        else if(B <= 0 || A <= 0)
            return 0;
        pair<int,int> key(A, B);
        auto iter = m.find(key);
        if(iter != m.end())
            return iter->second;
        double result = (soupServings2(A-100,B,m) +
                         soupServings2(A-75,B-25,m) +
                         soupServings2(A-50,B-50,m) +
                         soupServings2(A-25,B-75,m)) * 0.25;
        m.insert(pair<pair<int,int>,double>(key,result));
        return result;
    }*/
    double soupServings(int N) {
        if(N > 5000)
            return 1;
        /*map<pair<int,int>,double> results1;
        map<pair<int,int>,double> results2;
        double r1 = soupServings1(N, N, results1);
        double r2 = soupServings2(N, N, results2) / 2.0;
        return r1 + r2;*/
        map<pair<int,int>,double> results;
        return soupServings(N, N, results);
    }
};