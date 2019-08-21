/*set存合格的数 map存出现的数*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        unordered_set<int>myset;
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            if(mymap.count(nums[i]-k))
            {
                myset.insert(nums[i]-k);
            }
            if(mymap.count(nums[i]+k))
            {
                myset.insert(nums[i]);
            }
            mymap[nums[i]]++;
            
        }
        return myset.size();
        
        
        
    }
};