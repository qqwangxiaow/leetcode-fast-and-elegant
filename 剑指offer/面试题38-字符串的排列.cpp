//why not string &
//why //swap(s[start],s[i]);??
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string>ret;
        sort(s.begin(),s.end());
        helper(ret,s,0);
        return ret;
    }
    void helper(vector<string>&ret,string s,int start)
    {
        if(start==s.size())
        {
            ret.push_back(s);   
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(i>start&&(s[start]==s[i]))
                continue;
            swap(s[start],s[i]);
            helper(ret,s,start+1);
            //swap(s[start],s[i]);
        }
    }

    
};