class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> num;
        while(n > 0) {
            num.push_back(n % 10);
            n /= 10;
        }
        int max = 0;
        int i = 0;
        for(; i < num.size(); i++) {
            if(num[i] < max) {
                break;
            }
            else max = num[i];
        }
        if(i == num.size())
            return -1;
        int min = max + 1;
        int min_ind;
        for(int j = 0; j < i; j++) {
            if(num[j] > num[i] && min > num[j]) {
                min = num[j];
                min_ind = j;
            }
        }
        num[min_ind] = num[i];
        num[i] = min;
        // sort num[0..i-1]
        // descending order
        sort(num.begin(), num.begin()+i, greater<int>());
        int result = 0;
        for(int i = num.size() - 1; i >= 0; i--) {
            // max = 2,147,483,647‬
            if(result > 214748364)
                return -1;
            result *= 10;
            if(result > 2147483647 - num[i])
                return -1;
            result += num[i];
        }
        return result;
    }
};