//1.先swap2 再swap0
//2.swap的时候一定要判断i小于r或者大于l
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        for(int i=0;i<=r;i++)
        {
            while(nums[i]==2&&i<r)
            {
                swap(nums[i],nums[r--]);
            }
            while(nums[i]==0&&i>l)
            {
                swap(nums[i],nums[l++]);
            }
            
        }
    }
};