//binary search and prefix sum
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>prefix(arr.size()+1,0);
        for(int i=1;i<=arr.size();i++)
        {
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        int l=1,r=arr.back();
        while(l<r)
        {
            int m=l+(r-l)/2;
            getsum(arr,prefix,m)<target?l=m+1:r=m;
        }
        return abs(getsum(arr,prefix,l)-target)<abs(getsum(arr,prefix,l-1)-target)?l:l-1;
    }
    int getsum(vector<int>&arr,vector<int>&prefix,int value)
    {
        auto f=lower_bound(arr.begin(),arr.end(),value);
        int sum=prefix[f-arr.begin()]+(arr.end()-f)*value;
        return sum;
    }
};