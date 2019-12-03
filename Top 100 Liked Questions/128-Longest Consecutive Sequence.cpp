//keep track of nums[i]-1 and nums[i]+1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret=0;
        map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            if(!mymap[nums[i]])
            {
                int left=mymap.find(nums[i]-1)==mymap.end()?0:mymap[nums[i]-1];
                int right=mymap.find(nums[i]+1)==mymap.end()?0:mymap[nums[i]+1];
                int sum=left+right+1;
                mymap[nums[i]]=sum;
                ret=max(ret,mymap[nums[i]]);
                mymap[nums[i]-left]=sum;
                mymap[nums[i]+right]=sum;
            }
            else
                continue;
        }
        return ret;
    }
};