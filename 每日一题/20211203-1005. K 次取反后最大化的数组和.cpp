//垃圾代码
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(k--) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                if (i < nums.size() - 1)
                    i++;
            } else {
                if(i > 0) {
                    if (k % 2 == 1) {
                        break;
                    } else {
                        if (fabs(nums[i - 1]) < fabs(nums[i])) {
                            nums[i- 1] = -nums[i - 1];
                        } else {
                            nums[i] = -nums[i];
                        }
                        break;
                    }
                }
                else {
                    if (k % 2 == 0) {
                        nums[i] = -nums[i];
                    }
                    break;
                }
            }
        }
        int ret = 0;
        for (auto each : nums) {
            ret += each;
        }
        return ret;

    }
};