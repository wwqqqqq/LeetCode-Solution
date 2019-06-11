class Solution {
public:
    map<int,int> result;
    int numTrees(int n) {
        if(n == 0 || n == 1)
            return 1;
        if(n == 2)
            return 2;
        auto iter = result.find(n);
        if(iter != result.end())
            return iter->second;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += numTrees(i-1) * numTrees(n-i);
        }
        result.insert(pair<int,int>(n, sum));
        return sum;
    }
};