//prime set and count 1 (n&(n-1))
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        set<int>myset{2,3,5,7,11,13,17,19,23,29};
        int ret=0;
        for(int i=L;i<=R;i++)
        {
            int bits=0;
            int n=i;
            while(n)
            {
                bits++;
                n&=(n-1);
            }
            ret+=myset.count(bits);
            
        }
        return ret;
    }
   
};