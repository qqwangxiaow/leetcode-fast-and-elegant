class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ret(candies.size(),false);
        int maxCandies=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++)
        {
            if(maxCandies-candies[i]<=extraCandies)
            {
                ret[i]=true;
            }
        }
        return ret;
    }
};