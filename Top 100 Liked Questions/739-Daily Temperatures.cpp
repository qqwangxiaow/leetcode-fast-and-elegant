//using decrease stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>s;
        vector<int>ret(T.size(),0);
        for(int i=0;i<T.size();i++)
        {
            while(!s.empty()&&T[s.top()]<T[i])
            {
                ret[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
//brute force optimize solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ret(T.size());
        for(int i=T.size()-1;i>=0;i--)
        {
            int j=i+1;
            while(j<T.size()&&T[j]<=T[i])
            {
                if(ret[j]>0)
                {
                    j=ret[j]+j;
                }
                else
                {
                    j=T.size();
                }
            }
            if(j<T.size())
            {
                ret[i]=j-i;
            }
      
        }
        return ret;
    }
};