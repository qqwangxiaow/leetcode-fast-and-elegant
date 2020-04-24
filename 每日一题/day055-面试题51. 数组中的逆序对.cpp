//vector 用引用不会发生拷贝构造 所以需要用&
//merge的时候别忘了把nums[l,r]用temp[l,r]给代替了
lass Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int>temp(nums.size());
        int ret=0;
        mergesort(nums,0,nums.size()-1,temp,ret);
        return ret;
    }
    void mergesort(vector<int>&nums,int l,int r,vector<int>&temp,int &ret)
    {
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergesort(nums,l,m,temp,ret);
            mergesort(nums,m+1,r,temp,ret);
            int lpos=l,rpos=m+1,index=l;
            while(lpos<=m&&rpos<=r)
            {
                if(nums[lpos]>nums[rpos])
                {
                    ret+=m-lpos+1;
                    temp[index++]=nums[rpos++];
                }
                else
                {
                    temp[index++]=nums[lpos++];
                }
            }
            while(lpos<=m)
            {
                temp[index++]=nums[lpos++];
            }
            while(rpos<=r)
            {
                temp[index++]=nums[rpos++];
            }
            while(l<=r)
            {
                nums[l]=temp[l];
                l++;
            }
        }
    }
};