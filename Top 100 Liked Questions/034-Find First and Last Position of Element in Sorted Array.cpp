//两次搜索 第二次搜索mid要+1 这样才能找到右边的边界 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret(2,-1);
        if(nums.empty())
            return ret;
        int l=0,r=nums.size()-1;
        
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]<target)
            {
                l=m+1;
            }
            else
            {
                r=m;
            }
        }
        if(nums[l]!=target)
            return ret;
        else ret[0]=l;
        r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2+1;
            if(nums[m]>target)
            {
                r=m-1;
            }
            else
            {
                l=m;
            }
        }
        ret[1]=r;
        return ret;
        
    }
};