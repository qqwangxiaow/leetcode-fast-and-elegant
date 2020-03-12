//return mymap[target-nums[i]] not mymap[nums[i]]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            if(mymap.find(target-nums[i])!=mymap.end())
                return {i,mymap[target-nums[i]]};
            else
                mymap.emplace(nums[i],i);
        }
        return {};
    }
};