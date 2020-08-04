//topsort
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
            int temp=q.front();
            q.pop();
            ret.push_back(temp);
            for(auto each:graph[temp])
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