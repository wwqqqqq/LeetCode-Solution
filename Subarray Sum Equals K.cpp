class Solution {
public:
    void insert(map<int,int>& m, int e) {
        auto iter = m.find(e);
        if(iter == m.end())
            m.insert(pair<int,int>(e,1));
        else iter->second++;
    }
    int find(map<int,int>& m, int e) {
        auto iter = m.find(e);
        if(iter == m.end())
            return 0;
        return iter->second;
    }
    int subarraySum(vector<int>& nums, int k, int st, int ed) {
        if(st > ed)
            return 0;
        if(st == ed) {
            if(nums[st] == k)
                return 1;
            return 0;
        }
        int mid = (st + ed) / 2;
        map<int, int> left_sum;
        int sum = 0;
        insert(left_sum, 0);
        // O(nlogn)
        for(int i = mid-1; i >= st; i--) {
            sum += nums[i];
            insert(left_sum, sum);
        }
        int result = subarraySum(nums, k, st, mid-1) + subarraySum(nums, k, mid+1, ed);
        // O(nlogn)
        for(int i = mid; i <= ed; i++) {
            k -= nums[i];
            result += find(left_sum, k);
        }
        return result;
    }
    int subarraySum(vector<int>& nums, int k) {
        // is the integers in nums positve or?
        // there are three kinds of continuous subarrays nums[i..j]
        // mid = (0 + nums.size()-1)/2
        // 1. i <= mid <= j
        // 2. i <= j < mid
        // 3. mid < i <= j
        return subarraySum(nums, k, 0, nums.size()-1);
        // time complexity O(n(logn)^2)
        // t(n) = O(nlogn) + 2t(n/2) = O(nlogn) + 2(n/2 logn) + 4t(n/4) = O(nlogn) * logn
    }
};