//感觉不是二分 r-- 但是速度很快 最后直接return l就行
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>m)
            {
                r--;
            }
            else 
            {
                l=m+1;
            }
            
        }
        return l;

    }
};

//需要考虑返回条件
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==m)
            {
                l=m+1;
            }
            else 
            {
                r=m;
            }
            
        }
        return nums[l]>l?nums[l]-1:nums[l]+1;

    }
};