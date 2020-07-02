class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int m=matrix.size(),n=matrix[0].size();
        int l=matrix[0][0],r=matrix.back().back();
        while(l<r)
        {
            int m=l+(r-l)/2;
            int count=0;
            for(int i=0;i<matrix.size();i++)
            {
                auto f=upper_bound(matrix[i].begin(),matrix[i].end(),m);
                count+=f-matrix[i].begin();
            }
            if(count<k)
            {
                l=m+1;
            }
            else
            {
                r=m;
            }
        }
        return l;
    }
};