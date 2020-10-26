//可以用前缀和，分成100个桶，计算前面桶的个数
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy(nums);
        sort(copy.begin(),copy.end());
        map<int,int>mymap;
        for(int i=0;i<copy.size();i++)
        {
            if(!mymap.count(copy[i]))
                mymap[copy[i]]=i;
        }
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            ret.push_back(mymap[nums[i]]);
        }
        return ret;
    }
};