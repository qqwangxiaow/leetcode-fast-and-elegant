/*
dp[i]=dpmax(i-1)*A[i] or dp[i]=dpmin(-1)*A[i]
or A[i] itself
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret=nums[0];
        int pmin=nums[0],pmax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(pmin,pmax);
            }
            pmax=max(nums[i],pmax*nums[i]);
            pmin=min(nums[i],pmin*nums[i]);
            ret=max(ret,pmax);
        }
        return ret;
        
    }
};


