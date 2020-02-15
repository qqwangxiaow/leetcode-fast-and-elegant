//compair with right number
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
            else if(numbers[m]==numbers[r])
            {
                r=r-1;
            }
            else
            {
                r=m;
            }
        }
        return numbers[r];
    }
};