class Solution {
public:
    string convert(string s, int numRows) {
        // numRows + numRows - 2 = 2 * (numRows - 1)
        int n = 2 * (numRows - 1);
        string result;
        if(n <= 0)
            return s;
        for(int row = 0; row < numRows; row++) {
            for(int i = 0; i < s.size(); i++) {
                if(row == i % n || row == n - i % n)
                    result.append(1, s[i]);
            }
        }
        return result;
    }
};