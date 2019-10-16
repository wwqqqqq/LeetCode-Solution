class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
            return addStrings(num2, num1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        string result;
        for(int i = 0; i < num1.size(); i++) {
            int sum = num1[i] - '0' + carry;
            if(i < num2.size())
                sum += num2[i] - '0';
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else carry = 0;
            result.append(1, sum + '0');
        }
        if(carry == 1)
            result.append("1");
        reverse(result.begin(), result.end());
        return result;
    }
};