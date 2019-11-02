//straight forward
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecount=0,tencount=0,twentycountt=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                fivecount++;
            }
            else if(bills[i]==10)
            {
                if(fivecount<1)
                    return false;
                else
                {
                    fivecount--;
                    tencount++;
                }
                    
            }
            else 
            {
                if(tencount&&fivecount)
                {
                    tencount--;
                    fivecount--;
                }
                else if(fivecount>=3)
                {
                    fivecount-=3;
                }
                else
                {
                    return false;

                }       
            } 
        }
         return true;
    }
};