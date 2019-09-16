//注意空数组情况,clean solution
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt=0,ret=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||nums[i-1]<nums[i])
                ret=max(ret,++cnt);
            else 
                cnt=1;
        }
        return ret;
        
    }
};