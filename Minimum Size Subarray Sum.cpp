class Solution {
public:
    int find(vector<int>& arr, int e, int st, int ed) {
        // have to find the index of the first element that is larger or equal than e
        if(arr[st] >= e)
            return st;
        while(st <= ed) {
            int mid = (st + ed) / 2;
            if(arr[mid] == e)
                return mid;
            if(arr[mid] < e)
                st = mid + 1;
            else ed = mid - 1;
        }
        // st == ed + 1
        return st;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> count(nums.size(), 0); // count[i] is the sum of all elements in nums[0..i]
        // if we want to calculate the sum of nums[i..j], just use count[j] - count[i-1]
        // given i as the start point of the subarray, if we want to find if there is a j that sum(nums[i..j]) >= s, we can just find the minimum j that has count[j] > count[i-1] + s in the count vector
        // the time complexity of each find method is O(logn)
        // so the time complexity of the algorithm is O(nlogn)
        int sum = 0;
        int len = 0;
        for(int i = 0; i < count.size(); i++) {
            sum += nums[i];
            count[i] = sum;
            if(sum >= s && len == 0)
                len = i + 1;
        }
        if(sum < s)
            return 0;
        for(int i = 1; i < nums.size(); i++) {
            // the current minimum length is len
            // if the sum of nums[i..(i+len-1)] < s, we don't have to try it
            int ed = (i + len - 1) < nums.size()?(i+len-1):(nums.size()-1);
            if(count[ed] - count[i-1] < s)
                continue;
            // now we can find count[i-1] + s in vector count[i..(i+len-1)]
            int j = find(count, count[i-1]+s, i, ed);
            if(j <= ed && len > j - i + 1)
                len = j - i + 1;
        }
        return len;
    }
};