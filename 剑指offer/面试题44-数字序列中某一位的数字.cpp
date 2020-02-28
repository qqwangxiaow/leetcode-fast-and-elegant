// 9 90 900 9000
//sub then count index
class Solution {
public:
    int findNthDigit(int n) {
        long len=1,start=1,cnt=9;
        while(n-cnt*len>0)
        {
            n-=cnt*len;
            len++;
            cnt*=10;
            start*=10;
        }
        start+=(n-1)/len;   
        string str=to_string(start);
        return str[(n-1)%len]-'0';
    }
};