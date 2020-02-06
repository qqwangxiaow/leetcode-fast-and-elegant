//binary search 
//count num <= target for each row,so using upper_bound (>)
//l<=target  r>=target
//if(l==r) l=target;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) 
            return -1;
        int l=matrix[0][0],r= matrix.back().back();
        while(l<r)
        {
            int m=l+(r-l)/2;
            int count=0;
            for(int i=0;i<matrix.size();i++)
            {
                auto it=upper_bound(matrix[i].begin(),matrix[i].end(),m);
                count+=it-matrix[i].begin();
            }
            if(count<k)
                l=m+1;
            else
                r=m;
        }
        return l; 
        
    }
};