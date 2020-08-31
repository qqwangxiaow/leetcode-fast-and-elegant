//BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(),count=0;
        vector<int>visited(n);
        queue<int>q;
        visited[0]=1;
        q.push(0);
        while(!q.empty())
        {
            int to_pop=q.front();
            q.pop();
            count++;
            for(auto &it:rooms[to_pop])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return count==n;

    }
};

//DFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        count=0;
        visited.resize(n);
        dfs(rooms,0);
        return count==n;
    }
    void dfs(vector<vector<int>>&rooms,int x)
    {
        visited[x]=1;
        count++;
        for(auto &it:rooms[x])
        {
            if(!visited[it])
                dfs(rooms,it);
        }
    }
private:
    vector<int>visited;
    int count;
};