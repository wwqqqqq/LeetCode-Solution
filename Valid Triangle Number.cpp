// not best solution
// Can sort the vector first and reduce the time complexity to O(n^2)
class Solution {
public:
    int isTriangle(int a, int b, int c) {
        if(a > b && a > c) {
            if(a < b + c)
                return 1;
            else return 0;
        }
        else if(b > a && b > c) {
            if(b < a + c)
                return 1;
            else return 0;
        }
        else {
            if(c < a + b)
                return 1;
            else return 0;
        }
    }
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        for(auto iter1 = nums.begin(); iter1 != nums.end(); iter1++) {
            if(*iter1 <= 0)
                continue;
            for(auto iter2 = iter1 + 1; iter2 != nums.end(); iter2++) {
                if(*iter2 <= 0)
                    continue;
                for(auto iter3= iter2 + 1; iter3 != nums.end(); iter3++) {
                    if(*iter3 > 0 && isTriangle(*iter1, *iter2, *iter3))
                        count++;
                }
            }
        }
        return count;
    }
};