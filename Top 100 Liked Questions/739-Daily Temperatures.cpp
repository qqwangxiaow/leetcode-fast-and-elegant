//brute force optimize solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ret(T.size());
        for(int i=T.size()-1;i>=0;i--)
        {
            int j=i+1;
            while(j<T.size()&&T[j]<=T[i])
            {
                if(ret[j]>0)
                {
                    j=ret[j]+j;
                }
                else
                {
                    j=T.size();
                }
            }
            if(j<T.size())
            {
                ret[i]=j-i;
            }
      
        }
        return ret;
    }
};