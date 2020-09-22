class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int n = 2 * N;
        int sqrt_n = sqrt(n);
        int count = 0;
        for(int i = 1; i <= sqrt_n; i++) {
            int tmp = n % i;
            if(n % i == 0) {
                int x1 = n / i;
                int x2 = i;
                if(x1 + x2 > 1 && x1 > x2 - 1 && 
                   (x1 + x2 - 1) % 2 == 0 && (x1 - x2 + 1) % 2 == 0) {
                    count++;
                }
            }
        }
        return count;
    }
    // int estimateConsecutiveLength(int start, int target) {
    //     int length = target / start;
    //     while(length > 1) {
    //         if((2 * start + length) * (length + 1) <= 2 * target)
    //             return length;
    //         length = length / 2;
    //     }
    //     return length;
    // }
    // int consecutiveNumbersSum(int N) {
    //     // int count = 0;
    //     // for(int start = 1; start <= N; start++) {
    //     //     double x = 2 * (double)N + (double)start * start - start;
    //     //     double end = floor((sqrt(4 * x + 1) - 1) / 2);
    //     //     if(end * end + end - x == 0 || (end + 1) * (end + 1) + end + 1 - x == 0) {
    //     //         count++;
    //     //         start += 2;
    //     //     }
    //     // }
    //     // return count;
    //     int count = 0;
    //     int sum = 0;
    //     int start = 1;
    //     for(int end = 0; end <= N; end++) {
    //         sum += end;
    //         while(sum > N && start < end / 10000) {
    //             int estimate = estimateConsecutiveLength(start, end);
    //             sum -= (2 * start + estimate) * (estimate + 1) / 2;
    //             start = estimate + 1;
    //         }
    //         while(sum > N) {
    //             sum -= start;
    //             start++;
    //         }
    //         if(sum == N) {
    //             count++;
    //         }
    //     }
    //     return count;
    // }
};