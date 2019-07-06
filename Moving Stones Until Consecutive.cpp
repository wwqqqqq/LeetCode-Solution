class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // adjust order
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if(b > c) {
            int temp = b;
            b = c;
            c = temp;
        }
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        vector<int> result = {0,0};
        // if consecutive
        if(c == b + 1 && b == a + 1)
            return result;
        result[1] = c - a - 2;
        if(b == a + 1 || b == a + 2 || c == b + 1 || c == b + 2)
            result[0] = 1;
        else result[0] = 2;
        return result;
    }
};