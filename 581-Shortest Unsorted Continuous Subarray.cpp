/*右边没有比他小的，左边没有比它大的，就是正常的数，O(N)*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>minr(n);
        vector<int>maxl(n);
        for(int i=n-1,r=INT_MAX;i>=0;i--)
        {
            minr[i]=r=min(r,nums[i]);
        }
        for(int j=0,l=INT_MIN;j<n;j++)
        {
            maxl[j]=l=max(l,nums[j]);
        }
        int i=0,j=n-1;
        while(i<n&&nums[i]<=minr[i]) i++;
        while(i<j&&nums[j]>=maxl[j]) j--;
        return j-i+1;
    }
};
/*sort*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>nums2(nums);
        sort(nums2.begin(),nums2.end());
        int i=0,j=nums.size()-1;
        while(i<nums.size()&&nums[i]==nums2[i]) i++;
        while(i<j&&nums[j]==nums2[j]) j--;
        return j-i+1;
    }
};