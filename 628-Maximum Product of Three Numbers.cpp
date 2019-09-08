/*sort*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int temp1=nums[0]*nums[1]*nums[n-1];
        int temp2=nums[n-1]*nums[n-2]*nums[n-3];
        return max(temp1,temp2);
        
    }
};
/*dp,dp[0][j]代表j个数最大,dp[1][j]代表j个数最小*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int dp[2][4];
        dp[0][0]=1;
        dp[1][0]=1;
        for(int i=1;i<4;i++)
        {
            dp[0][i]=INT_MIN;
            dp[1][i]=INT_MAX;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=3;j>0;j--)
            {
                if(dp[0][j-1]==INT_MIN)
                    continue;
                dp[0][j]=max(dp[0][j],max(dp[0][j-1]*nums[i],dp[1][j-1]*nums[i]));
                dp[1][j]=min(dp[1][j],min(dp[0][j-1]*nums[i],dp[1][j-1]*nums[i]));
            }
        }
        return dp[0][3];
        
        
    }
};