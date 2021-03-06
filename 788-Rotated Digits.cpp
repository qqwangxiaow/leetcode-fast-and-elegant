//逐个分类检查
class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
                                //0  1  2  3  4  5  6  7  8  9
        vector<int> must_have = { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
        vector<int> cant_have = { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0};
        for(int i=1;i<=N;i++)
        {
            int m=0,c=0,num=i;
            while(num)
            {
                int n=num%10;
                if(must_have[n])
                {
                    m++;
                }
                if(cant_have[n])
                {
                    c++;
                    break;
                }
                num=num/10;
            }
            if(c)
                continue;
            if(!m)
            {
                continue;
            }
            res++;
            
        }
        return res;
    }
};