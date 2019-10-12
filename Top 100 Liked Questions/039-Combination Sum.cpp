//backtracking
//sort 很关键
//&&target>=candidates[i] 终止条件 和下一个start=i 不能忽略
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ret;
        vector<int>temp;
        helper(ret,temp,candidates,target,0);
        return ret;
    }
    void helper(vector<vector<int>>&ret,vector<int>&temp,vector<int>&candidates,int target,int start)
    {
        if(target==0)
        {
            ret.push_back(temp);
        }
        for(int i=start;i<candidates.size()&&target>=candidates[i];i++)
        {
            temp.push_back(candidates[i]);
            helper(ret,temp,candidates,target-candidates[i],i);
            temp.pop_back();
        }
    }
};