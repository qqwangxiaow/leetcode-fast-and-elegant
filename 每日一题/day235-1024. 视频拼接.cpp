//贪心
//找到每个i的最右边
//从0开始遍历到T，如果i到达当前last说明不可行
//如果i等于之前的某一个区间的最后，那么ret++

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int>maxn(T,0);
        int pre=0,last=0,ret=0;
        for(auto clip:clips)
        {
            if(clip[0]<T)
                maxn[clip[0]]=max(clip[1],maxn[clip[0]]);
        }
        for(int i=0;i<T;i++)
        {
            last=max(maxn[i],last);
            if(i==last)
                return -1;
            if(i==pre)
            {
                ret++;
                pre=last;
            }
        }
        return ret;
    }
};