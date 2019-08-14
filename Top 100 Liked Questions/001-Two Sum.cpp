/*map保存index */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mymap;
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            if(mymap.find(target-nums[i])!=mymap.end())
            {
                ret.push_back(mymap[target-nums[i]]);
                ret.push_back(i);
                return ret;
                
            }
            else 
            {
                mymap.insert(make_pair(nums[i],i));
            }
        }
        return ret;
        
    }
};
