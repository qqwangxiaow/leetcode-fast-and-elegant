//from begin and end
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ret(nums.size(),1);
        int n=nums.size();
        int frombegin=1,fromlast=1;
        for(int i=0;i<n;i++)
        {
            ret[i]*=frombegin;
            frombegin*=nums[i];
            ret[n-i-1]*=fromlast;
            fromlast*=nums[n-i-1];
        }
        return ret;
    }
};