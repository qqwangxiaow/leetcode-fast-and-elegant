//same as 207
//alter return value
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(ret.size()==numCourses)
            return ret;
        else return {};
    }
};
