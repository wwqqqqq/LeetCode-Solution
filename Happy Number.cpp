class Solution {
public:
    set<int> visited;
    bool isHappy(int n) {
        while(1) {
            if(n == 1)
                return true;
            if(n == 0)
                return false;
            if(visited.find(n) != visited.end())
                return false;
            visited.insert(n);
            int sum = 0;
            while(n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return false;
    }
};