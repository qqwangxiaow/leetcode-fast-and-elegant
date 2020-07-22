//跟最右边的比 三种情况
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0,r=numbers.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(numbers[m]>numbers[r])
            {
                l=m+1;
            }
            else if(numbers[m]<numbers[r])
            {
                r=m;
            }
            else
            {
                r=r-1;
            }
        }
        return numbers[r];
    }
};