class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int op1 = 0;
        int op2 = 0;
        int op = 0; // + = 0, - = 1
        int lastop = 0;
        while(i < s.size()) {
            for(; i < s.size(); i++)
                if(s[i] != ' ') break;
            int beg = i;
            if(s[i] == '(') {
                int lpcount = 1;
                int rpcount = 0;
                for(i++; i < s.size(); i++) {
                    if(s[i] == '(')
                        lpcount++;
                    else if(s[i] == ')')
                        rpcount++;
                    if(lpcount == rpcount) {
                        op2 = calculate(s.substr(beg+1, i-beg-1));
                        break;
                    }
                }
                for(i++; i < s.size(); i++) {
                    if(s[i] == '+') {
                        op = 0;
                        break;
                    }
                    else if(s[i] == '-') {
                        op = 1;
                        break;
                    }
                }
            }
            else {
                for(; i < s.size(); i++) {
                    if(s[i] == '+') {
                        op2 = calculate(s.substr(beg, i - beg));
                        op = 0;
                        break;
                    }
                    else if(s[i] == '-') {
                        op2 = calculate(s.substr(beg, i - beg));
                        op = 1;
                        break;
                    }
                }
                if(i >= s.size()) {
                    op2 = stoi(s.substr(beg));
                }
            }
            i++;
            op1 = (lastop == 0)?(op1 + op2):(op1 - op2);
            lastop = op;
        }
        return op1;
    }
};