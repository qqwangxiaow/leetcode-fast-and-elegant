//loop:swap 0 to l,swap 2 to r
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]==2&&i<r)
                swap(nums[i],nums[r--]);
            while(nums[i]==0&&i>l)
                swap(nums[i],nums[l++]);
        }
    }
};
