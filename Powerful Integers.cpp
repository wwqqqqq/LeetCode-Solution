/*
970. Powerful Integers
Given two non-negative integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
 

Note:

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> x_power;
        vector<int> y_power;
        int n = 1;
        if(x != 1) {
            while(n < bound) {
                x_power.push_back(n);
                n = n * x;
            }
        }
        else {
            x_power.push_back(1);
        }
        n = 1;
        if(y == 1) {
            y_power.push_back(1);
        }
        else {
            while(n < bound) {
                y_power.push_back(n);
                n = n * y;
            }
        }
        set<int> res;
        for(int i = 0; i < x_power.size(); i++) {
            for(int j = 0; j < y_power.size(); j++) {
                if(x_power[i] + y_power[j] > bound)
                    break;
                res.insert(x_power[i] + y_power[j]);
            }
        }
        vector<int> result(res.size());
        auto iter1 = res.begin();
        auto iter2 = result.begin();
        for(; iter1 != res.end(); iter1++, iter2++)
            *iter2 = *iter1;
        return result;
    }
};