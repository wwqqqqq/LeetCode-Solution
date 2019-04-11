class Solution {
public:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0)
            return result;
        
        int n = digits[digits.size()-1] - '0';
        string str = letters[n];
        
        if(digits.size() == 1) {
            for(int i = 0; i < str.size(); i++) {
                string s(1, str[i]);
                result.push_back(s);
            }
            return result;
        }
        
        vector<string> init = letterCombinations(digits.substr(0, digits.size() - 1));
        for(int i = 0; i < str.size(); i++) {
            vector<string> temp = init;
            for(int j = 0; j < temp.size(); j++) {
                temp[j].append(1, str[i]);
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};