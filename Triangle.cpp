class Solution {
public:
    int min(int i1, int i2) {
        return (i1 > i2) ? i2 : i1;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minimalNumber(triangle[triangle.size()-1]);
        for (int level = triangle.size()-2; level >= 0; level--) {
            for (int i = 0; i < triangle[level].size(); i++) {
                minimalNumber[i] = min(minimalNumber[i], minimalNumber[i+1]) + triangle[level][i];
            }
        }
        return minimalNumber[0];
    }
};