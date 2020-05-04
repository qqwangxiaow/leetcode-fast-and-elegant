//maxreach and end
//i==end step++
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach=0,step=0,end=0;
        int len=nums.size();
        for(int i=0;i<len-1;i++)
        {
            maxreach=max(nums[i]+i,maxreach);
            if(i==end)
            {
                step++;
                end=maxreach;
            }
        }
        return step;
        
    }
};