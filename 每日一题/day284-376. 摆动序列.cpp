//dp
//计算两个子序列，一个最后增，一个最后减少，都是钟摆序列
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int up=1,down=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                down=max(down,up+1);
            else if(nums[i]<nums[i-1])
                up=max(up,down+1);  
        }
        return max(up,down);
    }
};