class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size())
            return intersect(nums2, nums1);
        vector<int> result;
        if(nums1.size() == 0 || nums2.size() == 0)
            return result;
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); i++) {
            // use binary search to find if nums1[i] appears in nums2
            // do I have to worry about repeated elements?
            // because we are considering the intersection of two vectors, not the same value of two vectors
            // we should delete the element in nums2 if found nums1[i]
            int beg = 0, end = nums2.size()-1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                if(nums2[mid] == nums1[i]) {
                    nums2.erase(nums2.begin() + mid);
                    result.push_back(nums1[i]);
                    break;
                }
                else if(nums2[mid] > nums1[i])
                    end = mid - 1;
                else beg = mid + 1;
            }
        }
        return result;
    }
};