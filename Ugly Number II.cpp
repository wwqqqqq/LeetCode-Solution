class Solution {
public:
    bool isUgly(int num) {
        // the most obvious way
        if(num <= 0)
            return false;
        else if(num == 1)
            return true;
        else if(num % 2 == 0)
            return isUgly(num / 2);
        else if(num % 3 == 0)
            return isUgly(num / 3);
        else if(num % 5 == 0)
            return isUgly(num / 5);
        return false;
    }
    int min(int a, int b, int c) {
        if(a < b) {
            if(a < c)
                return a;
            return c;
        }
        else {
            if(b < c)
                return b;
            return c;
        }
        return a;
    }
    int nthUglyNumber(int n) {
        /* O(nlogn)
        int count = 0;
        for(int i = 0;; i++) {
            if(isUgly(n)) {
                count++;
                if(count == n)
                    return i;
            }
        }*/
        // from 1 to x, numbers whose prime factor is only 2:
        // log_2 x + 1
        // from 1 to x, numbers whose prime factor consist of only 2 and 3
        // (log_2 x + 1) + (log_2 (x/3) + 1) + (log_2 (x/3/3) + 1) ... + (log_2 (x / (3 ^log_3 x)) + 1)
        // = (log_2 x + 1) * (log_3 x + 1) - log_2 3 - 2 * log_2 3 - ... - (log_3 x) * (log_2 3)
        // = (log_2 x + 1) * (log_3 x + 1) - (1 + log_3 x) * (log_3 x) * (log_2 3) / 2
        // from 1 to x, numbers whose prime factor only include 2, 3, 5
        // .....
        /*
        arr = [1]
        arr = [1, 2, 3, 5]
        arr = [1, 2, 3, 5, 4, 6, 10, 6, 9, 15, 10, 15, 25]
        */
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> arr = {1};
        for(int i = 1; i < n; i++) {
            int t = min(arr[i2] * 2, arr[i3] * 3, arr[i5] * 5);
            arr.push_back(t);
            if(t == arr[i2] * 2)
                i2++;
            if(t == arr[i3] * 3)
                i3++;
            if(t == arr[i5] * 5)
                i5++;
        }
        return arr[n-1];
    }
};