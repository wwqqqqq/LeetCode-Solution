class Solution {
public:
    bool isprime(int x, set<int> &primes, set<int> &composites) {
        if(primes.find(x) != primes.end())
            return true;
        if(composites.find(x) != composites.end())
            return false;
        int s = (int)sqrt(x);
        for(int i = 2; i <= s && i < x; i++) {
            if(x % i == 0) {
                composites.insert(x);
                return false;
            }
        }
        primes.insert(x);
        return true;
    }
    int setbits(int x) {
        int c = 0;
        while(x != 0) {
            if(x & 1)
                c++;
            x = x >> 1;
        }
        return c;
    }
    int countPrimeSetBits(int L, int R) {
        set<int> primes;
        set<int> composites = {1};
        int count = 0;
        for(int i = L; i <= R; i++) {
            int bits = setbits(i);
            if(isprime(bits, primes, composites))
                count++;
        }
        return count;
    }
};