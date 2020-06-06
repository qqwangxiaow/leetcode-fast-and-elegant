class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromleft=1,fromright=1;
        vector<int>ret(n,1);
        for(int i=0;i<n;i++)
        {
            ret[i]*=fromleft;
            fromleft*=nums[i];
            ret[n-i-1]*=fromright;
            fromright*=nums[n-i-1];
        }
        return ret;
    }
};