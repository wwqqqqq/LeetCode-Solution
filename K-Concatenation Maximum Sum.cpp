class Solution {
public:
    int multiply(int sum, int k) {
        int result = 0;
        while(k > 0) {
            if(sum < 1000000007 / k)
                return result + sum * k;
            int times = 1000000007 / sum;
            k = k - times;
            result += times * sum;
            result -= 1000000007;
        }
        return result;
    }
    int findMaxSubarray(vector<int>& arr, int beg, int end) {
        if(beg == end) {
            if(arr[beg] > 0)
                return arr[beg];
            return 0;
        }
        else if(beg > end)
            return 0;
        int mid = (beg + end) / 2;
        int right_max = 0;
        int left_max = 0;
        int sum = 0;
        for(int i = mid-1; i >= beg; i--) {
            sum += arr[i];
            if(sum > left_max)
                left_max = sum;
        }
        sum = 0;
        for(int i = mid+1; i <= end; i++) {
            sum += arr[i];
            if(sum > right_max)
                right_max = sum;
        }
        int r1 = left_max + right_max + arr[mid];
        int r2 = findMaxSubarray(arr, beg, mid-1);
        if(r2 < r1)
            r2 = r1;
        int r3 = findMaxSubarray(arr, mid+1, end);
        if(r3 < r2)
            r3 = r2;
        return r3;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // if all positive, then k * sum(arr)
        // if sum(arr) >= 0, sum(arr) * (k-2) + max_sum_right(arr) + max_sum_left(arr)
        // if sum(arr) <= 0, max_sum_right(arr) + max_sum_left(arr) OR any sub-array...
        bool has_neg = false;
        bool has_pos = false;
        int sum = 0;
        int max_sum_left = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum > max_sum_left)
                max_sum_left = sum;
            if(arr[i] < 0)
                has_neg = true;
            else if(arr[i] > 0)
                has_pos = true;
        }
        if(has_neg = false) {
            return multiply(sum, k);
        }
        sum = 0;
        int max_sum_right = 0;
        for(int i = arr.size() -1; i >= 0; i--) {
            sum += arr[i];
            if(sum > max_sum_right)
                max_sum_right = sum;
        }
        if(sum > 0) {
            int result = multiply(sum, k-2);
            result = result + max_sum_left;
            //result = result % 1000000007;
            result = result + max_sum_right;
            //result = result % 1000000007;
            int t = findMaxSubarray(arr, 0, arr.size()-1);
            if(result < t)
                result = t;
            return result % 1000000007;
        }
        if(!has_pos)
            return 0;
        int result = (max_sum_right + max_sum_left);
        int t = findMaxSubarray(arr, 0, arr.size()-1);
        if(t > result)
            result = t;
        return result % 1000000007;
    }
};