class Solution {
public:
    int divide(int dividend, int divisor) {
        int i;
        int n = divisor;
        int sign = 1;
        int len = sizeof(int) * 8 - 1;
        int carry = 0;
        int MAX_INT = ~(1 << (len));
        if (dividend == (1 << len))
        {
            //-dividend does not exist
            carry = 1;
            dividend = MAX_INT;
            sign = -sign;
        }
        else if (dividend < 0)
        {
            sign = -sign;
            dividend = -dividend;
        }
        if (divisor == (1 << len))
        {
            //-divisor does not exist
            if (carry == 1) //-dividend does not exist either.
                return 1;
            return 0;
        }
        else if (divisor == -1 && carry == 1)
            return MAX_INT;
        else if (divisor < 0)
        {
            sign = -sign;
            divisor = -divisor;
            n = -n;
        }
        else if (divisor == 0)
            return MAX_INT;
        for (i = 0; i < len; i++)
        {
            if (i != 0)
                n = n << 1;
            if (n > dividend && i == 0)
                return 0;
            if (n > dividend && i != 0)
            {
                n = n >> 1;
                i = i - 1;
                break;
            }
            if (n >= (1 << (len - 1)))
                break;
            if (n == dividend)
            {
                if (sign == 1)
                    return (1 << i);
                else
                    return -(1 << i);
            }
        }
        if (i == len)
            i = len - 1;
        //cout << "n = " << n << endl;
        //cout << dividend << " = " << (1 << (i)) << "b + " << (dividend - n + carry) << endl;
        if (sign == 1)
            return (1 << i) + divide(dividend - n + carry, divisor);
        else
            return -((1 << i) + divide(dividend - n + carry, divisor));
    }
};


/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        // the divisor will not be 0
        int sign = 1;
        // before turn divident and divisor into a positive number
        // we must consider the corner case: they may equal to INT_MIN
        // -INI_MIN will be out of range of an integer
        int result = 0;
        //int intMin = -2147483648‬;
        if(divisor == INT_MIN) {
            if(dividend == INT_MIN)
                return 1;
            return 0;
        }
        if(divisor < 0) {
            sign = -sign;
            divisor = -divisor;
        }
        // now divisor is a positive number
        if(dividend == INT_MIN) {
            if(sign * divisor == -1)
                return INT_MAX;
            if(sign * divisor == 1)
                return INT_MIN;
            result = 1;
            dividend += divisor;
        }
        if(dividend < 0) {
            sign = -sign;
            dividend = -dividend;
        }
        vector<int> pow2;
        vector<int> pow2timesd;
        int current = divisor;
        int coefficient = 1;
        while(current <= dividend) {
            pow2.push_back(coefficient);
            pow2timesd.push_back(current);
            if(current > dividend - current)
                break;
            current = current * 2;
            coefficient = coefficient * 2;
        }
        for(int i = pow2timesd.size()-1; i >= 0; i--) {
            if(dividend >= pow2timesd[i]) {
                dividend -= pow2timesd[i];
                result += pow2[i];
            }
            if(dividend == 0)
                break;
        }
        return sign * result;
    }
};
*/