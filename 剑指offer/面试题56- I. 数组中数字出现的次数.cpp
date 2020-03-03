//find a bit that is diff
//separate nums into two parts
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int>ret(2,0);
        int temp=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            temp^=nums[i];
        }
        int diff=temp^(temp&(temp-1));
        for(auto num:nums)
        {
            if(num&diff)
            {
                ret[0]^=num;
            }
            else
            {
                ret[1]^=num;
            }
        }
        return ret;
    }
};