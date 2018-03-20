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