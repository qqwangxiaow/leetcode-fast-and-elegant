//slide window and +=(leftevencnt+1)*(rightevencnt+1);
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,oddcount=0;
        int evenright=0;
        int ret=0;
        while(r<nums.size())
        {
            if(nums[r++]&1)
            {
                oddcount++;
            }
            if(oddcount==k)
            {
                int temp=r;
                while(r<nums.size()&&((nums[r]&1)==0))
                {
                    r++;
                }
                int rightevencnt=r-temp;
                int leftevencnt=0;
                while((nums[l]&1)==0)
                {
                    leftevencnt++;
                    l++;
                }
                ret+=(leftevencnt+1)*(rightevencnt+1);
                l++;
                oddcount--;
            }
            
        }
        return ret;
    }
};

//前缀和 arr[j]代表到j为止odd的数量和
//那么 arr[i]-arr[j]==k 就是一个结果
//用twosum的思路优化 hash存某一个odd sum的count 然后累加
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ret=0;
        vector<int>prefix(nums.size()+1,0);
        prefix[0]=1;
        int sum=0;
        for(auto num:nums)
        {
            sum+=num&1;
            prefix[sum]++;
            if(sum>=k)
            {
                ret+=prefix[sum-k];
            }            
        }
        return ret;
    }
};
