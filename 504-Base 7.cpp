/*考虑0的特殊情况，注意返回字符串 */
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        int flag=0;
        if(num<0)
        {
            flag=1;
            num=-num;
        }
        string ret;
        while(num)
        {
            ret+=to_string(num%7);
            num=num/7;
        }
        if(flag)
        {
            ret+='-';
        }
        reverse(ret.begin(),ret.end());
        
        return ret;
        
    }
};