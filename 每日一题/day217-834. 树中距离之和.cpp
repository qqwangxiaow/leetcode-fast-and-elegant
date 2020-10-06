//dp表示子节点到该节点的距离和
//sz表示子节点的数量
//假设两个节点 x,y,则 ret[x]=ret[y]+sz[y]-sz[x]
//ret[0]=dp[0],0是根节点，可以通过第一遍dfs获得sz[0]和dp[0]
//公式推出来的，想象一下两个相邻节点x，y
//ret[x]=dp[x]+dp[y]+sz[y]
//ret[y]=dp[y]+dp[x]+sz[x]
//ret[x]=ret[y]+sz[y]-sz[x]=ret[y]+(N-sz[x])-sz[x]
//这里复用了dp来代表ret，因为先算父节点，再算子节点，所以可以覆盖
class Solution {
public:
    vector<vector<int>>graph;
    vector<int>sz,dp;
    void dfs(int u,int f)
    {
        for(auto &v:graph[u])
        {
            if(v==f)
                continue;
            dfs(v,u);
            dp[u]+=dp[v]+sz[v];
            sz[u]+=sz[v];
        }
    }
    void dfs2(int u,int f,int N)
    {
        for(auto &v:graph[u])
        {
            if(v==f)
                continue;
            dp[v]=dp[u]+(N-sz[v])-sz[v];
            dfs2(v,u,N);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        sz.resize(N,1);
        dp.resize(N,0);
        graph.resize(N,{});
        for(auto &edge:edges)
        {
            int u=edge[0],v=edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0,-1);
        dfs2(0,-1,N);
        return dp;
    }
};