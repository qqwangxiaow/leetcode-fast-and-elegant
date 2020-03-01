//merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret=0;
        vector<int>tmp(nums.size(),0);
        mergesort(nums,0,nums.size()-1,tmp,ret);
        return ret;
    }
    void mergesort(vector<int>&nums,int l,int r,vector<int>&tmp,int &ret)
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergesort(nums,l,mid,tmp,ret);
            mergesort(nums,mid+1,r,tmp,ret);
            int lpos=l,rpos=mid+1,tpos=l;
            while(lpos<=mid&&rpos<=r)
            {
                if(nums[rpos]<nums[lpos])
                {
                    tmp[tpos++]=nums[rpos++];
                    ret+=mid-lpos+1;
                }
                else
                {
                    tmp[tpos++]=nums[lpos++];
                }
            }
            while(lpos<=mid)
            {
                tmp[tpos++]=nums[lpos++];
            }
            while(rpos<=r)
            {
                tmp[tpos++]=nums[rpos++];
            }
            while(l<=r)
            {
                nums[l]=tmp[l];
                l++;
            }
        }
    }
};
//elegant version but slow
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return dfs(nums,0,nums.size());
    }
    int dfs(vector<int>&nums,int l,int r)
    {
        if(r-l<=1)
            return 0;
        int mid=(l+r)>>1;
        int res=dfs(nums,l,mid)+dfs(nums,mid,r);
        sort(nums.begin()+l,nums.begin()+mid);
        for(int i=mid;i<r;i++)
        {
            res+=nums.begin()+mid-upper_bound(nums.begin()+l,nums.begin()+mid,nums[i]);
        }
        return res;
    }

};