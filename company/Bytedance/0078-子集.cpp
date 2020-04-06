//i+1!!!!
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;
        vector<int>temp;
        helper(ret,nums,temp,0);
        return ret;
    }
    void helper(vector<vector<int>>&ret,vector<int>&nums,vector<int>temp,int start)
    {
        ret.push_back(temp);
        for(int i=start;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            helper(ret,nums,temp,i+1);
            temp.pop_back();
        }
    }
};