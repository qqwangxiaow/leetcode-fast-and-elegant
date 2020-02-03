//vector ret dosent cost space 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int frombegin=1,fromlast=1;
        int len=nums.size();
        vector<int>ret(len,1);
        for(int i=0;i<len;i++)
        {
            ret[i]*=frombegin;
            frombegin*=nums[i];
            ret[len-i-1]*=fromlast;
            fromlast*=nums[len-i-1];
        }
        return ret;
    }
};