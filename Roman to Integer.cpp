class Solution {
public:
    int romanToInt(string s) {
        const int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;
        vector<int> nums(s.size());
        for(int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'I': nums[i] = I; break;
                case 'V': nums[i] = V; break;
                case 'X': nums[i] = X; break;
                case 'L': nums[i] = L; break;
                case 'C': nums[i] = C; break;
                case 'D': nums[i] = D; break;
                case 'M': nums[i] = M; break;
                default:  nums[i] = 0; break;
            }
        }
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i + 1 < nums.size() && nums[i] < nums[i+1]) {
                result += nums[i + 1] - nums[i];
                i++;
            }
            else {
                result += nums[i];
            }
        }
        
        return result;
    }
};