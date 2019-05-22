class Solution {
public:
    string convertToTitle(int n) {
        // 没有0位的26进制
        string result = "";
        while(n != 0) {
            n = n - 1;
            int temp = n % 26;
            n = n / 26;
            result.append(1, temp + 'A');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};