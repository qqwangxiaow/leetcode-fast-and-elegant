//streamstring auto transform
class Solution {
public:
    int myAtoi(string str) {
        int ret=0;
        stringstream ss;
        ss<<str;
        ss>>ret;
        return ret;
    }
};


/*
judge overflow
if(ret>INT_MAX/10||(INT_MAX/10==ret&&num>7))
    return INT_MAX;
if(ret<INT_MIN/10||(INT_MIN/10==ret&&num<-8))
    return INT_MIN;
-2147483648~2147483647
if have 2 signs like "+-" return 0
*/
class Solution {
public:
    int myAtoi(string str) {
        int ret=0,len=(int)str.size(),neg=1;
        bool hassign=false,hasnum=false;
        for(int i=0;i<str.size();i++)
        {
            char c=str[i];
            if(ret==0&&!hassign&&!hasnum)
            {
                if(c==' ')
                    continue;
                if(c=='-'||c=='+')
                {
                    hassign=true;
                    neg=(c=='-')?-1:1;
                    continue;
                }     
            }
            if(c<='9'&&c>='0')
            {
                hasnum=true;
                int num=(c-'0')*neg;
                if(ret>INT_MAX/10||(INT_MAX/10==ret&&num>7))
                    return INT_MAX;
                if(ret<INT_MIN/10||(INT_MIN/10==ret&&num<-8))
                    return INT_MIN;
                ret=ret*10+num;
                continue;
            }
            break;
            
        }
        return ret;       
    }
};