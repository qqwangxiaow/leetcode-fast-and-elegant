//two pointers
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>>ret;
        int j;
        for(int i=0;i<S.size();i=j)
        {
            j=i+1;
            int count=1;
            while(j<S.size()&&S[j]==S[i])
            {
                count++;
                j++;
            
            }
            if(count>=3)
                ret.push_back({i,j-1});
        }
        return ret; 
    }
};