class Solution {
public:
    int ceilDivide(int a, int b) {
        // return ceil(a/b)
        if (a % b == 0) {
            return a / b;
        }
        int c = a/b;
        return a / b + 1;
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx != tx || sy != ty) {
            if ((sx > tx || sx+sy > ty) && (sx+sy > tx || sy > ty)) {
                return false;
            }
            if (tx > ty) {
                int n = ceilDivide(tx - max(ty,sx), ty);
                tx = tx - ty * n;
            }
            else if (ty > tx) {
                int n = ceilDivide(ty - max(tx,sy), tx);
                ty = ty - tx * n;
            }
            else {
                return false;
            }
        }
        return true;
    }
};