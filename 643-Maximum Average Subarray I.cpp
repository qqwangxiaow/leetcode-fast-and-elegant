/*slide window*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=k-1;
        int sum=0;
        for(int l=0;l<=j;l++)
        {
            sum+=nums[l];
            
        }
        int maxsum=sum;
        while(j<nums.size()-1)
        {
            sum-=nums[i];
            i++;
            j++;
            sum+=nums[j];
            if(maxsum<sum)
                maxsum=sum;
         }
        return (double)maxsum/k;
        
    }
};