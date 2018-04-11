class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        int count=0;
        double result;
        while(i<m&&j<n)
        {
            int min;
            if(nums1[i]<=nums2[j])
            {
                min=nums1[i];
                i++;
            }
            else
            {
                min=nums2[j];
                j++;
            }
            count++;
            if(2*count-1==m+n)
            {
                result=min;
                break;
            }
            else if(2*count==m+n)
            {
                result=min;
            }
            else if(2*(count-1)==m+n)
            {
                result=(result+min)/2.0;
                break;
            }
        }
        while(i<m)
        {
            count++;
            if(2*count-1==m+n)
            {
                result=nums1[i];
                break;
            }
            else if(2*count==m+n)
            {
                result=nums1[i];
            }
            else if(2*(count-1)==m+n)
            {
                result=(result+nums1[i])/2.0;
                break;
            }
            i++;
        }
        while(j<n)
        {
            count++;
            if(2*count-1==m+n)
            {
                result=nums2[j];
                break;
            }
            else if(2*count==m+n)
            {
                result=nums2[j];
            }
            else if(2*(count-1)==m+n)
            {
                result=(result+nums2[j])/2.0;
                break;
            }
            j++;
        }
        return result;
    }
};