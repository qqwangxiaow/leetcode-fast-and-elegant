/*sort*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dup=-1,missing=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                dup=nums[i];
            else if(nums[i]>nums[i-1]+1)
                missing=nums[i-1]+1;
        }  
        return {dup,nums[nums.size()-1]!=nums.size()?nums.size():missing};
    }
};
/*通过置-的方式找到重复项，然后没置-的地方就是这个数不存在，将1...n映射到nums[0]....nums[n-1]的位置,abs不能忘*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ret(2,0);
        for(auto each:nums)
        {
            if(nums[abs(each)-1]<0) ret[0]=abs(each);
            else
                nums[abs(each)-1]*=-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ret[1]=i+1;
        }
        return ret;
    }
};