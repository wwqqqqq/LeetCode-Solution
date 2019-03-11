// Runtime: 4ms, faster than 100.00% of C++ online submissions for Additive Number!
// BUG EXISTS!! Can only process sequences where all numbers can be stored in unsigned int.

class Solution {
public:
    int verify(unsigned int first, unsigned int second, int st, string num) {
        unsigned int third = first + second;
        string res = to_string(third);
        if(res.size() > num.size() - st)
            return -1;
        for(int i = 0; i < res.size(); i++)
            if(res[i] != num[st+i])
                return -1;
        return (st + res.size() - 1);
    } 
    bool isAdditiveNumber(string num) {
        // First, guess which are the first two numbers.
        // Verify the correctness of the guess.
        if(num.size() == 0)
            return false;
        int n = num.size();
        //if(num[0] == '0')
        //    return false;
        float imax = (float)2147483647;
        unsigned int n1 = 0, _n1 = 0;
        for(int i = 1; i < n - 1; i++) {
            if(num[0] == '0' && i != 1)
                break;
            int digit = num[i-1] - '0';
            if(_n1 >= (imax - num[i-1] + '0') / 10.0 )
                break;
            n1 = 10 * _n1 + digit;
            _n1 = n1;
            unsigned int n2 = 0, _n2 = 0;
            for(int j = i + 1; n - j >= i && n - j >= j - i; j++) {
                if(num[i] == '0' && j != i + 1)
                    break;
                n1 = _n1;
                digit = num[j-1] - '0';
                if(_n2 >= (imax - num[j-1] + '0') / 10.0 )
                    break;
                n2 = 10 * _n2 + digit;
                _n2 = n2;
                if(num[j] == '0' && (num[0] != '0' || num[i] != '0'))
                    continue;
                // 1st number: [0, i-1]
                // 2nd number: [i, j-1]
                // 3rd number: [j, ?]
                int st = j;
                while(1) {
                    int m = verify(n1, n2, st, num);
                    if(m == -1)
                        break;
                    if(m == n-1) {
                        return true;
                    }
                    unsigned int n3 = n1 + n2;
                    n1 = n2;
                    n2 = n3;
                    st = m + 1;
                }
            }
        }
        return false;
    }
};