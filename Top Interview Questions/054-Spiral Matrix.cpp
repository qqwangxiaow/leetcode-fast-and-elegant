//向右n次,然后向左n-1次,向下m次,向上m-1次.当减到0时就走完了
//用stepcount保存左右和上下的要走的次数,direction控制方向
//step%2 控制上下或者左右 step%4控制具体的某一方向
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].size()==0)
            return {};
        vector<vector<int>>direction{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int>ret;
        vector<int>stepcount{matrix[0].size(),matrix.size()-1};
        int row=0,col=-1;   
        int step=0;
        while(stepcount[step%2])
        {
            for(int i=0;i<stepcount[step%2];i++)
            {
                row+=direction[step][0];
                col+=direction[step][1];
                ret.push_back(matrix[row][col]);
            }
            stepcount[step%2]--;
            step=(step+1)%4;
        }
        return ret;
    }
};