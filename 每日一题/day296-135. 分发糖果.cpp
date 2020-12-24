//greedy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        vector<int>leftcount(ratings.size(), 1);
        vector<int>rightcount(ratings.size(), 1);
        for(int i = 1;i < ratings.size();++i){
            if(ratings[i] > ratings[i-1]){
                leftcount[i] = leftcount[i-1] + 1;
            }
            else
                leftcount[i] = 1;
        }
        for(int i=ratings.size()-2;i >= 0;--i){
            if(ratings[i] > ratings[i+1]){
                rightcount[i] = rightcount[i+1] + 1;
            }
            else
                rightcount[i] = 1;
        }
        for(int i = 0;i < ratings.size();++i){
            ret += max(leftcount[i], rightcount[i]);
        }
        return ret;
    }
};