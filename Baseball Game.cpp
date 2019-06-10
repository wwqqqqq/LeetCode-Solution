class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> validscores;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i][0] == 'C') {
                sum = sum - validscores.top();
                validscores.pop();
            }
            else if(ops[i][0] == 'D') {
                validscores.push(validscores.top() * 2);
                sum = sum + validscores.top();
            }
            else if(ops[i][0] == '+') {
                int last = validscores.top();
                validscores.pop();
                int result = last + validscores.top();
                validscores.push(last);
                validscores.push(result);
                sum = sum + result;
            }
            else {
                int result = atoi(ops[i].c_str());
                validscores.push(result);
                sum = sum + result;
            }
        }
        return sum;
    }
};