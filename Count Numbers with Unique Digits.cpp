class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        int result = 9;
        for(int i = 1; i < n; i++)
            result = result * (10 - i);
        return result + countNumbersWithUniqueDigits(n-1);
    }
};