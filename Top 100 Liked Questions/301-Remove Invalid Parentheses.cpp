//not too difficult 
//1.isvalid is easy to judge a string 
//2.str=temp.substr(0,i)+temp.substr(i+1) to test new string 
//3.unordered_set for clean duplicate
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ret;
        queue<string>q;
        unordered_set<string>visited;
        q.push(s);
        visited.insert(s);
        bool found=false;
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                string temp=q.front();
                q.pop();
                if(isvalid(temp))
                {
                    found=true;
                    ret.push_back(temp);
                }
                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]!='('&&temp[i]!=')')
                        continue;
                    string str=temp.substr(0,i)+temp.substr(i+1);
                    if(!visited.count(str))
                    {
                        q.push(str);
                        visited.insert(str);
                    }
                }
            }
            if(found)
                break;
        }
        return ret;
    }
    bool isvalid(string s)
    {
        int count=0;
        for(char c:s)
        {
            if(c=='(')
                count++;
            else if(c==')')
            {
                count--;
                if(count<0)
                    return false;
            }
        }
        return count==0;
    }
    
};