//partition
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        if(k>=arr.size())
            return arr;
        if(k==0)
            return {};
        int index=partition(arr,l,r);
        while(index!=k-1)
        {
            if(index<k-1)
            {
                l=index+1;
                index=partition(arr,l,r);
            }
            else if(index>k-1)
            {
                r=index-1;
                index=partition(arr,l,r);
            }
        }
        return vector<int>(arr.begin(),arr.begin()+k);
        
    }
    int partition(vector<int>&arr,int l,int r)
    {
        int pivot=arr[r];
        int ll=l-1;
        for(int i=l;i<r;i++)
        {
            if(arr[i]<=pivot)
            {
                ll++;
                swap(arr[ll],arr[i]);
            }
        }
        swap(arr[++ll],arr[r]);
        return ll;
    }
};
//using priority_queue
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<=0)
            return {};
        priority_queue<int>mypq;
        unordered_set<int>myset;
        for(int i=0;i<arr.size();i++)
        {
            if(mypq.size()<k)
            {
                
                mypq.push(arr[i]);
            }
            else
            {
                if(mypq.top()>arr[i])
                {
                    mypq.pop();
                    mypq.push(arr[i]);
                }
            }
        }
        vector<int>ret;
        while(!mypq.empty())
        {
            ret.push_back(mypq.top());
            mypq.pop();
        }
        return ret;
    }
};