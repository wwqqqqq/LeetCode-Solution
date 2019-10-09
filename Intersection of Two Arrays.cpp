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


/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // O(n1logn1 + n2logn2 + n1 + n2)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        vector<int> result;
        while(iter1 != nums1.end() && iter2 != nums2.end()) {
            if(*iter1 == *iter2) {
                result.push_back(*iter1);
                int temp = *iter1;
                while(iter1 != nums1.end() && *iter1 == temp)
                    iter1++;
                while(iter2 != nums2.end() && *iter2 == temp)
                    iter2++;
            }
            else if(*iter1 < *iter2) {
                iter1++;
            }
            else {
                iter2++;
            }
        }
        return result;
    }
};
*/