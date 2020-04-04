//don't forget f++
class Solution {
public:
    int myAtoi(string str) {
        int f=0;
        if(str.find_first_not_of(' ')!=str.npos)
        {
            f=str.find_first_not_of(' ');   
        }
        else
            return 0;
        int flag=1;
        if(str[f]=='+'||str[f]=='-')
        {
            flag=str[f++]=='+'?1:-1;
        }
        int num=0;
        while(f<str.size()&&(str[f]<='9'&&str[f]>='0'))
        {
            if(num>INT_MAX/10||(num==INT_MAX/10&&str[f]>'7'))
                return flag>0?INT_MAX:INT_MIN;
            else
                num=num*10+(str[f++]-'0');
        }
        return flag*num;
        
    }
};