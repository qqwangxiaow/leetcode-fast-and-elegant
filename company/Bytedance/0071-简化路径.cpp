//getline() and stringstream
class Solution {
public:
    string simplifyPath(string path) {
        string ret,temp;
        vector<string>myvec;
        stringstream ss(path);
        while(getline(ss,temp,'/'))
        {
            if(temp==""||temp==".")
                continue;
            if(temp==".."&&!myvec.empty())
                myvec.pop_back();
            else if(temp!="..")
            {
                myvec.push_back(temp);
            }
        }
        for(auto s:myvec)
            ret+="/"+s;
        return ret==""?"/":ret;
    }
};