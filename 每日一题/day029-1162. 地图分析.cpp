//bfs for each node 
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        if(q.empty()||q.size()==grid.size()*grid[0].size())
            return -1;
        pair<int,int>cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=cur.first+dirs[i][0];
                int col=cur.second+dirs[i][1];
                if(row>=0&&row<grid.size()&&col>=0&&col<grid[0].size()&&grid[row][col]==0)
                {
                    grid[row][col]=grid[cur.first][cur.second]+1;
                    q.push(make_pair(row,col));
                }
            }
        }
        return grid[cur.first][cur.second]-1;
    }
};