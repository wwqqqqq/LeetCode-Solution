class Solution {
public:
    int operatorPriority(char op) {
        if(op == '+' || op == '-') {
            return 1;
        }
        if(op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }
    int calculate(int operand1, int operand2, char op) {
        switch(op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: break;
        }
        return 0;
    }
    void performOneCalculation(stack<int>& operands, stack<char>& operators) {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        operands.push(calculate(operand1, operand2, operators.top()));
        operators.pop();
    }
    void addOperatorToStack(stack<int>& operands, stack<char>& operators, char op) {
        while(operators.size() >= 1 && operands.size() >= 2 && operatorPriority(operators.top()) >= operatorPriority(op)) {
            performOneCalculation(operands, operators);
        }
        operators.push(op);
    }
    bool isOperator(char c) {
        if(c == '+' || c == '-' || c == '*' || c == '/') {
            return true;
        }
        else
            return false;
    }
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                continue;
            }
            else if(isOperator(s[i])) {
                addOperatorToStack(operands, operators, s[i]);
            }
            else {
                // digits
                int start = i;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                int number = stoi(s.substr(start, i - start));
                operands.push(number);
                i--;
            }
        }
        while(operators.size() >= 1 && operands.size() >= 2) {
            performOneCalculation(operands, operators);
        }
        return operands.top();
    }
};