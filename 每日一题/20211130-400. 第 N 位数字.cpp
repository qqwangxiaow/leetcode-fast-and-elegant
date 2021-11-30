//就硬算
class Solution {
public:
    int findNthDigit(int n) {
       long long numbers=0,tempNums;
        int answer;
        int digits=1;
        while(numbers<n)
        {
            tempNums=(long long )9*digits*pow(10,digits-1);
            numbers+=tempNums;
            if(numbers>=n)
                break;
            digits++;
        }
        numbers-=tempNums;
        answer=(int)pow(10,digits-1)-1+(int)(n-numbers)/digits;
        if((n-numbers)%digits==0)
            return answer%10;
        return ((answer+1)/((int)pow(10,digits-(n-numbers)%digits)))%10;

    }
};