// 00 10 01 代表出现 0 1 2 次，一个循环
//考虑每个bit
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //00 01 10=0 1 2
        int firstbit=0,secondbit=0;
        for(auto num:nums)
        {
            firstbit=(firstbit^num)&~secondbit;
            secondbit=(secondbit^num)&~firstbit;
        }
        return firstbit;
    }
};