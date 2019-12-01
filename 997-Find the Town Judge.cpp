//Directed Graph
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>myvec(N+1,0);
        for(auto each:trust)
        {
            myvec[each[1]]++;
            myvec[each[0]]--;
        }
        for(int i=1;i<=N;i++)
        {
            if(myvec[i]==N-1)
                return i;
        }
        return -1;
    }
};