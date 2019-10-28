//one pass is ok
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last=-1,ret=0;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)
            {
                ret=last<0?i:max(ret,(i-last)/2);
                last=i;
            }
        }
        ret=max(ret,(int)seats.size()-last-1);
        return ret;
    }
};