//bfs and check
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ret=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dirs{{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[0][0]=1;
        while(!q.empty())
        {
            pair<int,int>mypair=q.front();
            q.pop();
            if(isvalid(mypair.first,mypair.second,k))
            {
                ret++;
                for(int i=0;i<4;i++)
                {
                    int newrow=mypair.first+dirs[i][0];
                    int newcol=mypair.second+dirs[i][1];
                    if(newrow>=0&&newcol>=0&&newrow<m&&newcol<n&&!visited[newrow][newcol]&&isvalid(newrow,newcol,k))
                    {
                        visited[newrow][newcol]=1;
                        q.push(make_pair(newrow,newcol));
                    }

                }
            }
                
        }
        return ret;


    }
    int getsum(int n)
    {
        int ret=0;
        while(n)
        {
            ret+=n%10;
            n=n/10;
        }
        return ret;
    }
    bool isvalid(int row,int col,int k)
    {
        return getsum(row)+getsum(col)<=k;
    }
};