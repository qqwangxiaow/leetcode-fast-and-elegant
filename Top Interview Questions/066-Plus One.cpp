//no push_front opt
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9)
                digits[i]=0;
            else
            {
                digits[i]++;
                return digits;
            }
        }
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};
//straight forward
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0,sum=0;
        vector<int>ret;
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>=0;i--)
        {
            sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
            if(!carry)
                break;
            if(i==0)
                digits.insert(digits.begin(),1);   
        }
        return digits;        
    }
};