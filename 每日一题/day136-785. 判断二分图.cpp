//bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i])
                continue;
            q.push(i);
            visited[i]=1;
            while(!q.empty())
            {
                int to_pop=q.front();
                q.pop();
                for(auto v:graph[to_pop])
                {
                    if(!visited[v])
                    {
                        visited[v]=-visited[to_pop];
                        q.push(v);
                    }  
                    else if(visited[v]==visited[to_pop])
                        return false;
                }
            }
        }
        return true;
    }
};