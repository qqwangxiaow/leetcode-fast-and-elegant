//upper_bound > target的第一个元素位置
//从小到大的数组是> 否则<
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it=is_sorted_until(nums.rbegin(),nums.rend());
        if(it!=nums.rend())
        {
            auto f=upper_bound(nums.rbegin(),it,*it);
            swap(*it,*f);
        }
        reverse(nums.rbegin(),it);
    }
};
