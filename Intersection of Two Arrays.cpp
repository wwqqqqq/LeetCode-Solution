class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> res;
        for(auto iter=nums1.begin();iter<nums1.end();iter++)
        {
            s.insert(*iter);
        }
        for(auto iter=nums2.begin();iter<nums2.end();iter++)
        {
            if(s.find(*iter)!=s.end()) 
            {
                res.push_back(*iter);
                s.erase(*iter);
            }
        }
        return res;
    }
};