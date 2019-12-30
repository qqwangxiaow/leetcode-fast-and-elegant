//ret is double
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size(),N2=nums2.size();
        if(N1<N2)
            return findMedianSortedArrays(nums2,nums1);
        int l=0,h=2*N2;
        while(l<=h)
        {
            int mid2=(l+h)/2;
            int mid1=N1+N2-mid2;
            double l1=mid1==0?INT_MIN:nums1[(mid1-1)/2];
            double l2=mid2==0?INT_MIN:nums2[(mid2-1)/2];
            double r1=mid1==2*N1?INT_MAX:nums1[mid1/2];
            double r2=mid2==2*N2?INT_MAX:nums2[mid2/2];  
            if(l1>r2)
            {
                l=mid2+1;
            }
            else if(l2>r1)
            {
                h=mid2-1;
            }
            else
            {
                return (max(l1,l2)+min(r1,r2))/2;
            }     
        }
        return -1;
    }
};