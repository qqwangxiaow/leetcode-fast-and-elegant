//在头尾记录目前连续子序列的长度 然后把他们串起来
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mymap;
        int ret=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!mymap[nums[i]])
            {
                int left=mymap.find(nums[i]-1)==mymap.end()?0:mymap[nums[i]-1];
                int right=mymap.find(nums[i]+1)==mymap.end()?0:mymap[nums[i]+1];
                int sum=left+right+1;
                mymap[nums[i]]=sum;
                ret=max(ret,sum);
                mymap[nums[i]-left]=sum;
                mymap[nums[i]+right]=sum;
            }
        }
        return ret;
    }
};