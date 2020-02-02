//greater means min-heap
//just push then pop
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mypq;
        for(int i=0;i<nums.size();i++)
        {
            mypq.push(nums[i]);
            if(mypq.size()>k)
            {
                mypq.pop();
            }
        }
        return mypq.top();
    }
};
//partition
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,len=nums.size(),r=len-1;
        while(1)
        {
            int idx=partition(nums,l,r);
            if(idx==len-k)
                return nums[idx];
            else if(idx<len-k)
                l=idx+1;
            else r=idx-1;
        }
        
    }
    int partition(vector<int>&arr,int low,int high)
    {
        int pivot=arr[high];
        int l=low-1;
        for(int i=low;i<=high-1;i++)
        {
            if(arr[i]<=pivot)
            {
                l++;
                swap(arr[l],arr[i]); //把小于pivot的都放在左边
            }
        }
        swap(arr[l+1],arr[high]);
        return (l+1);
    }
};