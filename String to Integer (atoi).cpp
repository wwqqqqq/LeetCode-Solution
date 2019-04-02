class Solution {
public:
    int myAtoi(string str) {
        int n = 0;
        int sign = 1;
        int i;
        for(i = 0; i < str.size(); i++) {
            if(str[i] != ' ')
                break;
        }
        if(i >= str.size())
            return 0;
        if(str[i] == '+')
            i++;
        else if(str[i] == '-') {
            sign = -1;
            i++;
        }
        
        int ofst = (sign == 1)? 0: 1;
        
        for(; i < str.size(); i++) {
            if(str[i] > '9' || str[i] < '0')
                break;
            int digit = str[i] - '0';
            if(n > INT_MAX / 10)
                return (sign == 1)? INT_MAX : INT_MIN;
            n *= 10;
            if(digit == 0)
                continue;
            int temp = digit - ofst;
            if(n >= INT_MAX - temp)
                return (sign == 1)? INT_MAX : INT_MIN;
            n += digit;
        }

        
        return n * sign;
    }
};