class Solution {
public:
    int gcd(int a, int b){
        if(a < b){
            swap(a, b);
        }
        if(b == 0){
            return a;
        }
        else{
            return gcd(b, a%b);
        }
    }
    
    
    double lcm(int a, int b){
        double result = (double)a * double(b);
        result = result / gcd(a, b);
        return result;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        double a_b_lcm = lcm(a, b);
        double a_c_lcm = lcm(a, c);
        double b_c_lcm = lcm(b, c);
        double a_b_c_lcm = lcm((int)a_b_lcm, c);
        // num = x / a + x / b + x / c - x / a_b_lcm - x / a_c_lcm - x / b_c_lcm + x / a_b_c_lcm
        // num = x * (1 / a + 1 / b + 1 / c - 1 / a_b_lcm - 1 / a_c_lcm - 1 / b_c_lcm + 1/ a_b_c_lcm)
        double f = 1.0 / a + 1.0 / b + 1.0 / c - 1.0 / a_b_lcm - 1.0 / a_c_lcm - 1.0 / b_c_lcm + 1.0 / a_b_c_lcm;
        int estimate = int(n / f);
        int N = estimate / a + estimate / b + estimate / c - (int)(estimate / a_b_lcm) - (int)(estimate / a_c_lcm) - (int)(estimate / b_c_lcm) + (int)(estimate / a_b_c_lcm);
        if(N == n) {
            for(int i = estimate; i >= 1; i--) {
                if(i % a == 0 || i % b == 0 || i % c == 0) {
                    return i;
                }
            }
            return 0;
        }
        else if(N > n) {
            int count = N;
            for(int i = estimate; i >= 1; i--) {
                if(i % a == 0 || i % b == 0 || i % c == 0) {
                    if(count == n)
                        return i;
                    count--;
                }
            }
            return 0;
        }
        int count = N;
        for(int i = estimate+1; i <= 2000000000; i++) {
            if(i % a == 0 || i % b == 0 || i % c == 0) {
                count++;
                if(count == n)
                    return i;
            }
        }
        /* Brute Force
        int count = 0;
        for(int i = 1; i <= 2000000000; i++) {
            if(i % a == 0 || i % b == 0 || i % c == 0) {
                count++;
                if(count == n)
                    return i;
            }
        }*/
        return 0;
    }
};