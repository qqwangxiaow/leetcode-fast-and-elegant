//backtrack
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;
        vector<int>tmp;
        helper(ret,tmp,nums,0);
        return ret;
    }
    void helper(vector<vector<int>>&ret,vector<int>&tmp,vector<int>&nums,int start)
    {
        ret.push_back(tmp);
        for(int i=start;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            helper(ret,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};
//iterative
//遍历的是nums,根据之前的ret插入num,n保存ret.size()
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret{{}};
        for(int num:nums)
        {
            int n=ret.size();
            for(int i=0;i<n;i++)
            {
                ret.push_back(ret[i]);
                ret.back().push_back(num); 
            }
        }
        return ret;
    }
};
//bit
//len代表返回结果长度 0...len每个数字代表一个结果 
//假设有ABC三个数,那么有8种结果 001 010 100 分别代表A,B,C
//000 {} 001 {A} 010{B} 100 {C} 
// &表示i这个结果有这个数,那么就把这个数push进来
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int len=1<<n;
        vector<vector<int>>ret(len);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i&(1<<j))
                {
                    ret[i].push_back(nums[j]);
                }
            }
        }
        return ret;
    }
};