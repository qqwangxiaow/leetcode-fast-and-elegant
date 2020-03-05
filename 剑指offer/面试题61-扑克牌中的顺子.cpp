//no sort min and max
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int>myvec(14,0);
        int minvalue=INT_MAX,maxvalue=INT_MIN;
        for(auto num:nums)
        {
            if(num==0)
                continue;
            else if(myvec[num])
            {
                return false;
            }
            else
            {
                myvec[num]++;
                minvalue=min(minvalue,num);
                maxvalue=max(maxvalue,num);
            }
        }
        return maxvalue-minvalue<=4;
    }
};
//sort and count 
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int interval=0;
        int count0=0;
        int i=0;
        for(;i<nums.size()&&nums[i]==0;i++)
        {
            if(nums[i]==0)
                count0++;
        }
        i++;
        for(;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                return false;
            interval+=(nums[i]-nums[i-1])>1?(nums[i]-nums[i-1]-1):0;
        }
        return count0>=interval;
    }
};