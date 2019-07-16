class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i = 0; i < tasks.size(); i++)
            count[tasks[i]-'A']++;
        vector<int> last_interval(26, -1);
        int result = 0;
        for(int i = 0;; i++) {
            int sum = 0;
            int max = 0;
            int choice = -1;
            for(int j = 0; j < 26; j++) {
                if(last_interval[j] == -1 || last_interval[j] + n < i)
                    if(count[j] > max) {
                        max = count[j];
                        choice = j;
                    }
                sum += count[j];
            }
            if(sum == 0)
                break;
            if(choice != -1) {
                count[choice]--;
                last_interval[choice] = i;
            }
            result++;
        }
        return result;
    }
};