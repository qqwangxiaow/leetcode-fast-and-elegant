class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int m=num1.size()-1,n=num2.size()-1;
        int carry=0;
        while(n>=0||m>=0||carry)
        {
            int sum=0;
            if(m>=0)
            {
                sum+=(num1[m]-'0');
                m--;
            }
            if(n>=0)
            {
                sum+=(num2[n]-'0');
                n--;
            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ret+=sum+'0';
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};