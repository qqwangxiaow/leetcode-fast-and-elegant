//interative
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        for(int reach=0;i<nums.size()&&i<=reach;i++)
        {
            reach=max(reach,nums[i]+i);
        }
        return i==nums.size();   
    }
};
//from behind
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1,i;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]+i>=last)
            {
                last=i;
            }
        }
        return last<=0;
    }
};