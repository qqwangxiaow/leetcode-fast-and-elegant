//((str[f++]-'0))
class Solution {
public:
    int myAtoi(string str) {
        int f=0;
        if(str.find_first_not_of(' ')!=string::npos)
            f=str.find_first_not_of(' ');
        else return 0;
        int flag=1,num=0;
        if(str[f]=='+'||str[f]=='-')
            flag=str[f++]=='+'?1:-1;
        while(f<str.size()&&(str[f]>='0'&&str[f]<='9'))
        {
            if(num>INT_MAX/10||(num==INT_MAX/10&&str[f]>'7'))
            {
                return flag==1?INT_MAX:INT_MIN;
            }
            num=num*10+(str[f++]-'0');
        }
        return flag*num;
        
    }
};