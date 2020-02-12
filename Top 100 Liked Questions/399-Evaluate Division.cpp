//graph and bfs
//mymap[a]=[b,val] means a/b=val;
//a/d=a/b*b/c*c/d

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        while(n--)
        {
            mymap[equations[n][0]].push_back({equations[n][1],values[n]});
            mymap[equations[n][1]].push_back({equations[n][0],1.0/values[n]});
        }
        vector<double>ret;
        for(auto &vec:queries)
        {
            ret.push_back(getdist(vec[0],vec[1]));
        }
        return ret;
    }
private:
    unordered_map<string,vector<pair<string,double>>>mymap;
    double getdist(string &a,string &b)
    {
        auto it1=mymap.find(a);
        auto it2=mymap.find(b);
        if(it1==mymap.end()||it2==mymap.end())
            return -1.0;
        if(a==b)
            return 1.0;
        queue<pair<string,double>>q;
        q.push({a,1.0});
        unordered_map<string,int>visited;
        visited[a]=1;
        double ret=-1.0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            visited[f.first]=1;
            if(f.first==b)
            {
                ret=f.second;
                break;
            }
            for(auto &p:mymap[f.first])
            {
                if(visited[p.first]==0)
                {
                    q.push({p.first,p.second*f.second});
                }
            }
        }
        return ret;
    }
};


//union set
//I don't konw
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unionSet u;
        for(int i=0;i<equations.size();i++)
        {
            u.merge(equations[i][0],equations[i][1],values[i]);
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(u.ask(queries[i][0],queries[i][1]));
        }
        return ans;
    }
private:
    class unionSet{
        private:
            unordered_map<string,string>fa;
            unordered_map<string,double>val;
            bool exist(const string&x)
            {
                return fa.find(x)!=fa.end();
            }
            void init(const string&x)
            {
                if(exist(x))
                    return;
                val[x]=1;
                fa[x]=x;
            }
            string getFather(const string&x)
            {
                if(fa[x]==x)
                    return x;
                else
                {
                    string f=getFather(fa[x]);
                    val[x]=val[x]*val[fa[x]];
                    return fa[x]=f;
                }
            }
        public:
            void merge(const string &a,const string &b,double v)
            {
                init(a);init(b);
                string aa=getFather(a),bb=getFather(b);
                fa[bb]=aa;
                val[bb]=val[a]*1.0/val[b]*v;
            }
            double ask(const string &a,const string &b)
            {
                if(!exist(a)||!exist(b))
                    return -1;
                string aa=getFather(a),bb=getFather(b);
                if(aa!=bb)
                    return -1;
                return val[b]*1.0/val[a];
            }
    };
};