class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        if(x % 10 == 0)
            return false;
        vector<int> vec;
        while(x != 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0; i < vec.size(); i++) {
            int j = vec.size() - i - 1;
            if(i >= j) break;
            if(vec[i] != vec[j]) return false;
        }
        return true;
    }
};