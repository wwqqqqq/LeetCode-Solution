class Solution {
public:
    string convertToBase7(int num) {
        string result;
        int sign = 1;
        if(num < 0) {
            sign = -1;
            num = - num;
        }
        else if(num == 0)
            return "0";
        while(num > 0) {
            int d = num % 7;
            num = num / 7;
            result.insert(0, 1, d + '0');
        }
        if(sign == -1)
            result.insert(0, 1, '-');
        return result;
    }
};