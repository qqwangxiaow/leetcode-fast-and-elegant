//从最左边的数开始 如果存在小1的数那就不是开头
//注意是最长 连续 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset;
        for(auto num:nums)
        {
            myset.insert(num);
        }
        int ret=0;
        for(const int &num:myset)
        {
            if(!myset.count(num-1 ))
            {
                int currentnum=num;
                int currentret=1;
                while(myset.count(currentnum+1))
                {
                    currentnum+=1;
                    currentret+=1;
                }
                ret=max(currentret,ret);
            }
        }
        return ret;

    }
};