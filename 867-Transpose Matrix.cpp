//straight forward
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r=A.size(),c=A[0].size();
        vector<vector<int>>B(c,vector<int>(r));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                B[j][i]=A[i][j];
        }
        return B;
    }
};