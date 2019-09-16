class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        int half = n / 2;
        double result = myPow(x, half);
        result = result * result;
        if(n > half * 2)
            result = result * x;
        else if(n < half * 2) {
            result = result / x;
        }
        return result;
    }
};