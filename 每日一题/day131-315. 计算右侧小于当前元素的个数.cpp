class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ret(n,0);
        vector<pair<int,int>>myvec;
        for(int i=0;i<nums.size();i++)
        {
            myvec.emplace_back(make_pair(nums[i],i));
        }
        merge(myvec,0,n,ret);
        return ret;
    }
    void merge(vector<pair<int,int>>&nums,int l,int r,vector<int>&ret)
    {
        if(r-l<=1)
            return;
        int m=l+(r-l)/2;
        merge(nums,l,m,ret);
        merge(nums,m,r,ret);
        int right=m;
        for(int left=l;left<m;left++)
        {
            while(right!=r&&nums[left]>nums[right])
                right++;
            ret[nums[left].second]+=right-m;
        }
        inplace_merge(nums.begin()+l,nums.begin()+m,nums.begin()+r);
    }
};