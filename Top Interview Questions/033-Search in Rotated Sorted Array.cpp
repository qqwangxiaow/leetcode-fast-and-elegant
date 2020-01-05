//1.l<=r
//2.nums[mid]>nums[r]
//3.nums[l]<=targeta nums[r]>=target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>nums[r])
            {
                if(nums[l]<=target&&nums[mid]>target)
                {
                    r=mid-1;
                }
                else 
                    l=mid+1;  
            }
            else
            {
                if(nums[r]>=target&&nums[mid]<target)
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};