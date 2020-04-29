//find peak and binary search
//lambda int key(int);
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int l=0,r=len-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(mountainArr.get(m)<mountainArr.get(m+1))
                l=m+1;
            else
                r=m;
        }
        int peak=l;
        int index=binarysearch(mountainArr,0,peak,target,[](int x){return x;});
        if(index!=-1)
            return index;
        index=binarysearch(mountainArr,peak+1,len-1,target,[](int x){return -x;});
        return index;
    }
    int binarysearch(MountainArray &mountainArr,int l,int r,int target,int key(int))
    {
        target=key(target);
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int cur=key(mountainArr.get(m));
            if(cur==target)
                return m;
            else if(cur<target)
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};