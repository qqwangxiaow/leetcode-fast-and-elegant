//l,r
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0)
            return {};
        int l=0,r=arr.size()-1;
        int index=partition(arr,l,r);
        while(index!=k-1)
        {
            if(index<k-1)
            {
                l=index+1;
                index=partition(arr,l,r);
            }
            else
            {
                r=index-1;
                index=partition(arr,l,r);
            }
        }
        return vector<int>(arr.begin(),arr.begin()+k);

    }
    int partition(vector<int>&nums,int l,int r)
    {
        int ll=l-1;
        int pivot=nums[r];
        for(int i=l;i<r;i++)
        {
            if(nums[i]<nums[r])
            {
                ll++;
                swap(nums[i],nums[ll]);
            }
        }
        swap(nums[++ll],nums[r]);
        return ll;

    }
};