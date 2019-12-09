//like find cycle begin in linklist
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow,fast;
        if(nums.size()>1)
        {
            slow=nums[0];
            fast=nums[nums[0]];
            while(slow!=fast
            {
                slow=nums[slow];
                fast=nums[nums[fast]];
            }
            int slow=0;
            while(fast!=slow)
            {
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
        return -1;
    }
};
//Pigeonhole principle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1,r=nums.size()-1,count=0;
        while(l<r)
        {
            int m=l+(r-l)/2;
            count=0;
            for(int num:nums)
            {
                if(num<=m)
                    count++;
            }
            if(count<=m)
                l=m+1;
            else
                r=m;
        }
        return l;
    }
};
