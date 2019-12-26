//map return index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ret(2,0);
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            if(mymap.find(target-nums[i])!=mymap.end())
            {
                ret[0]=mymap[target-nums[i]];
                ret[1]=i;
                break;
            }
            mymap[nums[i]]=i;;
        }
        return ret;  
    }
};