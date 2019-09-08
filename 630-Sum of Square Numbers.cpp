/*sqrt*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++)
        {
            
            if((int)sqrt(c-i*i)*(int)(sqrt(c-i*i))==c-i*i)
                return true;
        }
        return false;
        
        
    }
};
/*二分*/
class Solution {
public:
    bool judgeSquareSum(int c) {
       if(c<0)
           return false;
        long long  left=0,right=(int)sqrt(c);
        while(left<=right)
        {
            long long cur=left*left+right*right;
            if(cur==c)
                return true;
            else if(cur<c)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return false;
        
        
    }
};