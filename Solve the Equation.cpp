class Solution {
public:
    int s2i(string s) {
        if(s.size() == 0)
            return 1;
        if(s.size() == 1 && s[0] == '-')
            return -1;
        return atoi(s.c_str());
    }
    string solveEquation(string equation) {
        int left = 1;
        int x = 0;
        int cons = 0;
        int beg = 0;
        int sign = 1;
        bool endwithx = false;
        bool minus = true;
        for(int i = 0; i < equation.size(); i++) {
            if(equation[i] == 'x') {
                x += left * sign * s2i(equation.substr(beg, i-beg));
                i++;
                if(i >= equation.size()) {
                    endwithx = true;
                    break;
                }
                minus = false;
                if(equation[i] == '+')
                    sign = 1;
                else if(equation[i] == '-')
                    sign = -1;
                else if(equation[i] == '=') {
                    left = -1;
                    sign = 1;
                    minus = true;
                }
                beg = i+1;
            }
            else if(equation[i] == '+') {
                cons += left * sign * s2i(equation.substr(beg, i-beg));
                sign = 1;
                beg = i+1;
                minus = false;
            }
            else if(equation[i] == '-' && !minus) {
                cons += left * sign * s2i(equation.substr(beg, i-beg));
                sign = -1;
                beg = i+1;
                minus = false;
            }
            else if(equation[i] == '=') {
                cons += left * sign * s2i(equation.substr(beg, i-beg));
                left = -1;
                sign = 1;
                beg = i+1;
                minus = true;
            }
            else minus = false;
        }
        if(!endwithx)
            cons += left * sign * s2i(equation.substr(beg));
        if(x==0) {
            if(cons == 0)
                return "Infinite solutions";
            else return "No solution";
        }
        int result = -cons / x;
        string r = "x=";
        r.append(to_string(result));
        return r;
    }
};