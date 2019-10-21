// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
        int ed = n;
        while(st <= ed) {
            if(st == ed && isBadVersion(st))
                return st;
            int mid = st / 2 + ed / 2;
            if(isBadVersion(mid))
                ed = mid;
            else st = mid + 1;
        }
        return -1;
    }
};