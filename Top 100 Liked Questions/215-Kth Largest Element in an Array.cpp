//priority_queue<Type, Container, Functional> 
//greater<int> means min-heap
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
        int l=0,r=nums.size()-1,kth;
        while(1)
        {
            int idx=partition(nums,l,r);
            if(idx==k-1)
            {
                kth=nums[idx];
                break;
            }
            else if(idx<k-1)
            {
                l=idx+1;
            }
            else
            {
                r=idx-1;
            }
        }
        return kth; 
    }
    int partition(vector<int>&nums,int left,int right)
    {
        int pivot=nums[left];
        while(left<right)
        {
            while(left<right&&nums[right]<=pivot)
            {
                right--;
            }
            if(left<right)
            {
                nums[left]=nums[right];
            }
            while(left<right&&nums[left]>pivot)
            {
                left++;
            }
            
            if(left<right)
            {
                nums[right]=nums[left];
            }
        }
        nums[left]=pivot;
        return left;
    }
    
};

//partition2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,kth;
        while(1)
        {
            int idx=partition(nums,l,r);
            if(idx==k-1)
            {
                kth=nums[idx];
                break;
             }
            else if(idx<k-1)
            {
                l=idx+1;
            }
            else
            {
                r=idx-1;
            }
        }
        return kth; 
    }
    int partition(vector<int>&arr,int low,int high)
    {
        int pivot=arr[high];
        int l=low-1;
        for(int i=low;i<=high-1;i++)
        {
            if(arr[i]>pivot)
            {
                l++;
                swap(arr[l],arr[i]);
            }
        }
        swap(arr[l+1],arr[high]);
        return (l+1);
    }
        

};