//map and queue,like bfs

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*>mymap;
        int count=0;
        for(int i=0;i<employees.size();i++)
        {
            mymap[employees[i]->id]=employees[i];
        }
        queue<Employee*>q;
        if(mymap.count(id)==0)
            return 0;
        q.push(mymap[id]);
        while(!q.empty())
        {
            Employee *temp=q.front();
            count+=temp->importance;
            if(!temp->subordinates.empty())
            {
                for(int j=0;j<temp->subordinates.size();j++)
                {
                    q.push(mymap[temp->subordinates[j]]);
                }
            }
            q.pop();
        }
        return count; 
        
    }
};