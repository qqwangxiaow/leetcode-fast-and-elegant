//top sort
//关键是构建图 不一定要存邻接矩阵 邻接表更加省力
//将入度为0的点放入队列 进行统计
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses,vector<int>());
        vector<int>indegrees(numCourses,0);
        for(auto prerequisite:prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            indegrees[prerequisite[0]]++;
        }
        queue<int>q;
        vector<int>ret;
        for(int i=0;i<numCourses;i++)
        {
            if(!indegrees[i])
            {
                q.push(i);
            } 
        }
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            ret.push_back(tmp);
            for(auto each:graph[tmp])
            {
                if(--indegrees[each]==0)
                {
                    q.push(each);
                }     
            }
        }
        return ret.size()==numCourses;
    }
};