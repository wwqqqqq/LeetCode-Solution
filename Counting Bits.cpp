class Solution {
public:
    vector<int> countBits(int num) {
        /*// O(n) method:
        f[1] = f[0] + 1
        f[2] = f[0] + 1
        f[3] = f[1] + 1
        f[4] = f[0] + 1
        f[5] = f[1] + 1
        f[6] = f[2] + 1
        f[7] = f[3] + 1
        f[8] = f[0] + 1
        f[9] = f[1] + 1
        */
        vector<int> result(num+1, 0);
        int step = 1;
        int nextstep = 1;
        for(int i = 1; i <= num; i++) {
            if(i == nextstep) {
                nextstep = i * 2;
                step = i;
            }
            result[i] = result[i-step] + 1;
        }
        return result;
        /* O(n*sizeof(integer)) method
        vector<int> bits = {0};
        vector<int> result = {0};
        int sum = 0;
        for(int i = 1; i <= num; i++) {
            if(i % 2 == 1) {
                bits[0] = 1;
                sum++;
                result.push_back(sum);
                continue;
            }
            bits[0] = 0;
            sum--;
            int j;
            for(j = 1; j < bits.size(); j++) {
                if(bits[j] == 0) {
                    bits[j] = 1;
                    sum++;
                    break;
                }
                bits[j] = 0;
                sum--;
            }
            if(j >= bits.size()) {
                bits.push_back(1);
                sum++;
            }
            result.push_back(sum);
        }
        return result;*/
    }
};