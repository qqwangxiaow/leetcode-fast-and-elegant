/*用map记录,为想差为1的两个count之和*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mymap;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]++;
        }
        for(auto each:mymap)
        {
            if(mymap.count(each.first-1)>0)
                res=max(res,each.second+mymap[each.first-1]);
            
        }
        return res;
        
    }
};