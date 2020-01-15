//backtrack no return format
//注意是回溯时候是i+1 不是start+1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;
        vector<int>temp;
        helper(ret,nums,temp,0);
        return ret;
    }
    void helper(vector<vector<int>>&ret,vector<int>&nums,vector<int>&temp,int start)
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

//iteritive
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret={{}};
        int n=nums.size();
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

//bit  111 代表都在 101 代表第一个第三个在
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
                    ret[i].push_back(nums[j]);
            }
        }
        return ret;
    }
    
};