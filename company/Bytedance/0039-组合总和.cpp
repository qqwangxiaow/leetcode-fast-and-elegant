//sort and i &&target>=candidates[i]
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ret;
        vector<int>temp;
        helper(ret,candidates,temp,0,target);
        return ret;
    }
    void helper(vector<vector<int>>&ret,vector<int>&candidates,vector<int>&temp,int start,int target)
    {
        if(target==0)
        {
            ret.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size()&&target>=candidates[i];i++)
        {
            temp.push_back(candidates[i]);
            helper(ret,candidates,temp,i,target-candidates[i]);
            temp.pop_back();
        }
    }
};