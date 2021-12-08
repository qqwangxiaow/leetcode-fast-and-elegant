//3 slide window 主要是写法， 从2 * k第三个起始位置开始累加 然后减
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int max1 = 0, max12 = 0, max123 = 0, max2 = 0, max3 =0;
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int index1 = 0, index121 = 0, index122 = 0;
        vector<int> ans;
        for(int i = 2 * k; i < nums.size(); ++i) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1) {
                if (sum1 > max1) {
                    max1 = sum1;
                    index1 = i - 3 * k + 1;
                }
                if (max1 + sum2 > max12) {
                    max12 = max1 + sum2;
                    index121 = index1;
                    index122 = i - 2 * k +1;
                }
                if (max12 + sum3 > max123) {
                    max123 = max12 + sum3;
                    ans = {index121, index122, i - k +1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};