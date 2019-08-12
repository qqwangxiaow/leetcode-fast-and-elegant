/*到sqrt，注意减重*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1)
            return 0;

        
        int count=1;
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                count+=i;
                count+=num/i;
                if(i==sqrt(num))
                    count-=i;
            }
        }
        if(count==num)
            return 1;
        else 
            return 0;
        
    }
};