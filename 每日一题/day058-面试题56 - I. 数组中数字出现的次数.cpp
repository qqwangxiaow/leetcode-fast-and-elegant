//a&(a-1) 把a最后面的1弄成0
//再^获取最后一位1
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int diff=0;
        for(auto num:nums)
        {
            diff^=num;
        }
        diff=diff^(diff&(diff-1));
        int ret1=0,ret2=0;
        for(auto num:nums)
        {
            if(num&diff)
            {
                ret1^=num;
            }
            else
                ret2^=num;
        }
        return {ret1,ret2};
        

    }
};