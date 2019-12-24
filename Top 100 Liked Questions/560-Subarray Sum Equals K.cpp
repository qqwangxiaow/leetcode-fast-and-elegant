//sum(i..j)=sum(0...j)-sum(0...i)
//using map to keep prefix sum
//pay attention to insert 0 for init
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,ret=0;
        map<int,int>mymap;
        mymap[0]++;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mymap.count(sum-k))
                ret+=mymap[sum-k];
            mymap[sum]++;
        }
        return ret;
    }
};