//heapsort
//adjust(nums,size,index); 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums,nums.size());
        return nums;
    }
    void adjust(vector<int>&nums,int size,int index)
    {
        int l=index*2+1;
        int r=index*2+2;
        int maxindex=index;
        if(l<size&&nums[maxindex]<nums[l])  //maxindex not index
        {
            maxindex=l;
        }
        if(r<size&&nums[maxindex]<nums[r])
        {
            maxindex=r;
        }
        if(maxindex!=index)
        {
            swap(nums[index],nums[maxindex]);  
            adjust(nums,size,maxindex);       //adjust maxindex
        }

    }
    void heapsort(vector<int>&nums,int size)
    {
        for(int i=size/2-1;i>=0;i--)
        {
            adjust(nums,size,i);
        }
        for(int i=size-1;i>=1;i--)
        {
            swap(nums[0],nums[i]);
            adjust(nums,i,0);
        }

    }
};
//quicksort 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        quicksort(nums,l,r);
        return nums;
    }
    void quicksort(vector<int>&nums,int l,int r)
    {
        if(l<r)
        {
            int m=partition(nums,l,r);
            quicksort(nums,l,m-1);
            quicksort(nums,m+1,r);
        }
    }
    int partition(vector<int>&nums,int l,int r)
    {

        int pivot=nums[r];
        int ll=l-1;
        for(int i=l;i<r;i++)
        {
            if(nums[i]<pivot)
            {
                swap(nums[++ll],nums[i]);
            }
        }
        swap(nums[++ll],nums[r]);
        return ll;
    }
};
//