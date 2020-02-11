//backstacking
//pay attention to start=i and 
//string temp=s.substr(0,i)+s.substr(i+1); begin from 0;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ret;
        int l=0,r=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') l++;
            else if(s[i]==')' && l>0) l--;
            else if(s[i]==')' && l<=0) r++;
        }
        helper(ret,s,l,r,0);
        return ret;
    }
    void helper(vector<string>&ret,string s,int l,int r,int start)
    {
        if(l==0&&r==0&&isvalid(s))
        {
            ret.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(i!=start&&s[i]==s[i-1])
                continue;
            string temp=s.substr(0,i)+s.substr(i+1);
            if(s[i]=='('&&l>0)
            {
                helper(ret,temp,l-1,r,i);
            }
            else if(s[i]==')'&&r>0)
            {
                helper(ret,temp,l,r-1,i);
            }
        }
    }
    bool isvalid(string s)
    {
        int l=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') l++;
            else if(s[i]==')') l--;
            if(l<0) return false;
        }
        return true;
    }
};
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