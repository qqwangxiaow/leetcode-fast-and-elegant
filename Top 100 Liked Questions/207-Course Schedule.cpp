//topsort using matrix to save graph
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>matrix(numCourses,vector<int>(numCourses,0));
        vector<int>indegree(numCourses,0);
        for(auto prerequisite:prerequisites)
        {
            int cur=prerequisite[0];
            int pre=prerequisite[1];
            if(matrix[pre][cur]==0)
                indegree[cur]++;
            matrix[pre][cur]=1;
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            count++;
            for(int i=0;i<numCourses;i++)
            {
                if(matrix[curr][i]!=0)
                {
                    if(--indegree[i]==0)
                    q.push(i);   
                }   
            }
        }
        return count==numCourses;    
    }
};