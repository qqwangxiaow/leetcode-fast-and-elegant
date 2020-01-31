//nums[m]>m+1 那么左边一定有 想想就是了
//关键是要判断m和m+1 又要考虑越界的问题 那么这里r=m很关键 不会越界 
//因为只有l=r时候 m才会等于r 所以这里m都小于r m+1不会越界
//为什么r=m呢？ 因为m本身有可能是峰值

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>nums[m+1])
            {
                r=m;
            }
            else
                l=m+1;
        }
        return l;
    }
};