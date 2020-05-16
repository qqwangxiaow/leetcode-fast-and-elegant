//prefixsum use map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mymap;
        int ret=0,sum=0;
        mymap[0]++;
        for(int num:nums)
        {
            sum+=num;
            if(mymap.count(sum-k))
                ret+=mymap[sum-k];
            mymap[sum]++;
        }
        return ret;
    }
};