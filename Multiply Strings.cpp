class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result(num1.size()+num2.size(), 0);
        for(int i = num1.size() - 1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            for(int j = num2.size() - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int ind = (num1.size() - 1 - i) + (num2.size() - 1- j);
                result[ind] += n1 * n2;
                for(; ind < result.size()-1; ind++)
                    if(result[ind] >= 10) {
                        result[ind+1] += result[ind] / 10;
                        result[ind] = result[ind] % 10;
                    }
            }
        }
        int ind;
        for(ind = result.size() - 1; ind >= 0; ind--)
            if(result[ind] != 0)
                break;
        string s;
        for(; ind >= 0; ind--)
            s.append(1, result[ind] + '0');
        if(s.size() == 0)
            return "0";
        return s;
    }
};