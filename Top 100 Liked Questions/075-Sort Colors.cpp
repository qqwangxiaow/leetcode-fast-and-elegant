//将2换到右边 0换到左边
//注意一定要先换2 不能先换0  否则{1,2,0}会失效
 class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        for(int i=0;i<=right;i++)
        {
            while(nums[i]==2&&i<right)
            {
                swap(nums[i],nums[right--]);
            }
            while(nums[i]==0&&i>left)
            {
                swap(nums[i],nums[left++]);
            }
            
        }
    }
};