/*读两个队列进行cut，其中每个队列都有2N个位置，L = (N-1)/2, R=N/2,meadian=(L+R)/2
A1: [# 1 # 2 # 3 # 4 # 5 #]    (N1 = 5, N1_positions = 11)
A2: [# 1 # 1 # 1 # 1 #]     (N2 = 4, N2_positions = 9)*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size();
        int N2=nums2.size();
        if(N1<N2) return findMedianSortedArrays(nums2,nums1);
        int l=0,h=2*N2;
        while(l<=h)
        {
            int mid2=(l+h)/2;
            int mid1=N1+N2-mid2;
            double L1=mid1==0?INT_MIN:(nums1[(mid1-1)/2]);
            double L2=mid2==0?INT_MIN:(nums2[(mid2-1)/2]);
            double R1=mid1==N1*2?INT_MAX:(nums1[(mid1)/2]);
            double R2=mid2==N2*2?INT_MAX:(nums2[(mid2)/2]);
            if(L1>R2)
            {
                l=mid2+1;   
            }
            else if(L2>R1)
            {
                h=mid2-1;
                
            }
            else 
            {
                return (max(L1,L2)+min(R1,R2))/2;
            }
        }
        return -1;
        
    }
};