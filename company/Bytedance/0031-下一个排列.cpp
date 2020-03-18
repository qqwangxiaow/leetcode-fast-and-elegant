//找一个大数交换 然后将大数后面要全部排列一下才是最小
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it=is_sorted_until(nums.rbegin(),nums.rend());
        if(it!=nums.rend())
        {
            swap(*it,*upper_bound(nums.rbegin(),it,*it));
        }
        reverse(nums.rbegin(),it);
    }
};