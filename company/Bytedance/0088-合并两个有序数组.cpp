class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n-1;
        m--,n--;
        while(m>=0&&n>=0)
        {
            if(nums1[m]>nums2[n])
                nums1[len--]=nums1[m--];
            else
                nums1[len--]=nums2[n--];
        }
        while(n>=0)
            nums1[len--]=nums2[n--];   
    }
};