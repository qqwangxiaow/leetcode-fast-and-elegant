//调用库函数
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}
//is_sorted_until返回失序位置的迭代器 upper_bound( begin,end,num,greater<type>())
//返回小于num的地址
//最后排序
//Narayana Pandita algorithm
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto i=is_sorted_until(nums.rbegin(),nums.rend());
        if(i!=nums.rend())
            swap(*i,*upper_bound(nums.rbegin(),i,*i));
        reverse(nums.rbegin(),i);
    }
};