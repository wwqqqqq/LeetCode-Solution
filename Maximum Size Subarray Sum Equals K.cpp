class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // there are an easy way to calculate sum from nums[i] to nums[j]
        // sum(i, j) = sum(0, j) - sum(0, i-1)
        // for each index j, in order to find if there is an i so that sum(i,j)==k.
        // we only need to find if (sum(0,j)-k) already exists in our map
        map<int,int> m;
        // the key of the map is the sum of nums[0..i] and i the the value of the corresponding entry
        // if there are more than one i that the sums of nums[0..i] are the same, we take the smallest i as the value (because the question asks to return the maximum length of a subarray)
        int sum = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum == k) {
                int len = i+1;
                if(len > max) max = len;
            }
            else {
                int key = sum-k;
                auto iter = m.find(key);
                if(iter != m.end()) {
                    int len = i - iter->second;
                    if(len > max) max = len;
                }
            }
            
            auto iter = m.find(sum);
            if(iter != m.end())
                continue;
            else m.insert(pair<int,int>(sum, i));
        }
        return max;
    }
};