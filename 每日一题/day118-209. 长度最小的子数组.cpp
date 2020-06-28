class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int ret=INT_MAX;
        for(int i=prefix.size()-1;i>=0&&prefix[i]>=s;i--)
        {
            int j=upper_bound(prefix.begin(),prefix.begin()+i,prefix[i]-s)-prefix.begin();
            ret=min(ret,i-j+1);
        }
        
        return ret==INT_MAX?0:ret;
    }
};