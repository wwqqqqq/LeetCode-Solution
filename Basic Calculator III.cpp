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
    int calculate(long operand1, long operand2, char op) {
        switch(op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: break;
        }
        return 0;
    }
    void performUnaryCalculation(stack<long>& operands, stack<char>& operators) {
        int operand = operands.top();
        operands.pop();
        int op = operators.top();
        operators.pop();
        if(op == '-') {
            operands.push(-operand);
        }
        else if(op == '+') {
            operands.push(operand);
        }
    }
    void performBinaryCalculation(stack<long>& operands, stack<char>& operators) {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        operands.push(calculate(operand1, operand2, operators.top()));
        operators.pop();
    }
    void performOneCalculation(stack<long>& operands, stack<char>& operators) {
        if(operators.size() == 0 || operands.size() == 0) {
            return;
        }
        if(operands.size() == 1) {
            performUnaryCalculation(operands, operators);
        }
        else {
            performBinaryCalculation(operands, operators);
        }
    }
    void addOperatorToStack(stack<long>& operands, stack<char>& operators, char op) {
        while(operators.size() >= 1 && operatorPriority(operators.top()) >= operatorPriority(op)) {
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
        stack<long> operands;
        stack<char> operators;
        for(int i = 0; i < s.size(); i++) {
            char tmp = s[i];
            if(s[i] == ' ') {
                continue;
            }
            else if(s[i] == '(') {
                // paran
                int start = i;
                int parenCount = 1;
                for(i += 1; i < s.size() && parenCount > 0; i++) {
                    if(s[i] == '(') parenCount++;
                    else if(s[i] == ')') parenCount--;
                    if(s[i] == ')' && parenCount == 0) {
                        long number = (long)(calculate(s.substr(start + 1, i - start - 1)));
                        operands.push(number);
                        break;
                    }
                }
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
                long number = stol(s.substr(start, i - start));
                operands.push(number);
                i--;
            }
        }
        while(operators.size() >= 1 && operands.size() >= 0) {
            performOneCalculation(operands, operators);
        }
        if(operands.size() > 0)
            return operands.top();
        return 0;
    }
};