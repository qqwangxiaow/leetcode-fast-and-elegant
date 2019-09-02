/*find min  注意empty*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row=INT_MAX,col=INT_MAX;
        if(ops.empty())
            return m*n;
        for(int i=0;i<ops.size();i++)
        {
            row=min(ops[i][0],row);
            col=min(ops[i][1],col);
        }
        return row*col;
        
        
        
    }
};