//greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach=0;
        int step=0;
        int end=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxreach=max(maxreach,nums[i]+i);
            if(i==end)
            {
                step++;
                end=maxreach;
            }
        }
        return step;
    }
};