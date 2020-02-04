//like find cycle in list
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];

        }
        while(slow!=fast);
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
//Pigeonhole principle
//m is the median of array 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            int cnt=0;
            for(auto num:nums)
            {
                if(num<=m)
                    cnt++;
            }
            if(cnt>m)
                r=m;
            else
                l=m+1;
        }
        return l;
    }
};