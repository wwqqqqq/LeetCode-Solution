class Solution {
public:
    int primes(int n) {
        set<int> p;
        for(int i = 2; i <= n; i++) {
            bool isPrime = true;
            for(auto iter = p.begin(); iter != p.end(); iter++) {
                if(i % (*iter) == 0) {
                    isPrime = false;
                    break;
                }
                else if((*iter) * (*iter) > i)
                    break;
            }
            if(isPrime)
                p.insert(i);
        }
        return p.size();
    }
    int numPrimeArrangements(int n) {
        int nPrime = primes(n);
        int nNonPrime = n - nPrime;
        int result = 1;
        for(int i = nPrime; i >= 2; i--) {
            if(result < 1000000007 / i) {
                result *= i;
                continue;
            }
            int t = result;
            for(int j = 1; j < i; j++) {
                result += t;
                result = result % 1000000007;
            }
            //result = result % 1000000007;
        }
        for(int i = nNonPrime; i >= 2; i--) {
            if(result < 1000000007 / i) {
                result *= i;
                continue;
            }
            int t = result;
            for(int j = 1; j < i; j++) {
                result += t;
                result = result % 1000000007;
            }
            //result = result % 1000000007;
        }
        return result;
    }
};