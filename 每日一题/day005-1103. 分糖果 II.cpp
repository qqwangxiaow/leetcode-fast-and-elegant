class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ret(num_people,0);
        int index=0;
        int count=1,rest=candies;
        while(rest)
        {
            for(int i=0;i<num_people;i++)
            {
                if(rest>=count)
                {
                    ret[i]+=count;
                    rest-=count;
                    count++;
                }
                else if(rest==0)
                {
                    return ret;
                }
                else
                {
                    ret[i]+=rest;
                    rest=0;
                }

            }
        
        }
        return ret;
    }
};