//multi-source bfs
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ret(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                    visited[i][j]=1;
                }
            }
        }
        int count=0;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                pair<int,int>temp=q.front();
                q.pop();
                ret[temp.first][temp.second]=count;
                for(int j=0;j<4;j++)
                {
                    int newrow=temp.first+dirs[j][0];
                    int newcol=temp.second+dirs[j][1];
                    if(newrow>=0&&newcol>=0&&newrow<m&&newcol<n&&!visited[newrow][newcol])
                    {
                        q.push(make_pair(newrow,newcol));
                        visited[newrow][newcol]=1;
                    }
                    
                }
                
            }
            count++;
        }
        return ret;

    }
};