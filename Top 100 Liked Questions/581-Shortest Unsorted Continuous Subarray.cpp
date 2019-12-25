//sort O(nlogn)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>unsorted(nums);
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<nums.size()&&nums[l]==unsorted[l])
        {
            l++;
        }
        while(r>=l&&nums[r]==unsorted[r])
        {
            r--;
        }
        return r-l+1;
        
        
    }
};
/**
 * nums:  [2, 6, 4, 8, 10, 9, 15]
 * minr:   2  4  4  8   9  9  15
 *         <--------------------
 * maxl:   2  6  6  8  10 10  15
 *         -------------------->
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>maxleft(nums);
        vector<int>minright(nums);
        for(int i=1;i<nums.size();i++)
        {
            maxleft[i]=max(maxleft[i],maxleft[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            minright[i]=min(minright[i],minright[i+1]);
        }
        int l=0,r=nums.size()-1;
        while(l<nums.size()&&nums[l]<=minright[l])
        {
            l++;
        }
        while(r>l&&nums[r]>=maxleft[r])
        {
            r--;
        }
        return r-l+1;
        
    }
};