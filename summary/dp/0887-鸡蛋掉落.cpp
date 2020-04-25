//calc表示N个鸡蛋 times尝试能搞几层楼
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int>dp(K+1,0);
        int m=0;
        int t=1;
        while(calc(K,t)<N+1)
        {
            t++;
        }
        return t;
    }
    int calc(int N,int times)
    {
        if(N==1||times==1)
            return times+1;
        else
            return calc(N,times-1)+calc(N-1,times-1);
    }
};