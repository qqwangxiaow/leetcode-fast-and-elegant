//total当前最大能表示的数，遇到nums[i]后两种情况
//[1,total]U[1+nums[k],total+nums[k]]U[nums[k],nums[k]]
//一种情况是无缝隙，直接累加nums[i]，一种有缝隙，贪心添加total+1
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long total = 0;
        int ret = 0;
        int index = 0;
        while(total < n){
            if(index < nums.size() && nums[index] <= total+1){
                total += nums[index++];
            }
            else{
                total = total + (total + 1);
                ret++;
            }
        }
        return ret;
    }
};


