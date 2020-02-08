//using map to keep times 
//divide and conquer
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>mymap;
        for(auto ch:s)
        {
            mymap[ch]++;
        }
        bool flag_all=true,flag_no=true;
        for(auto it:mymap)
        {
            if(it.second<k)
                flag_all=false;
            else
                flag_no=false;
        }
        if(flag_all)
            return s.size();
        if(flag_no)
            return 0;
        int ret=0;
        vector<string>myvec;
        int i=0;
        while(i<s.size())
        {
            while (i<s.size()&&mymap[s[i]]<k) 
                i++;
            int j;
            for(j=i+1;j<s.size();j++)
            {
                if(mymap[s[j]]<k)
                {
                    myvec.push_back(s.substr(i,j-i));
                    break;
                } 
            }
            if(j==s.size())
                myvec.push_back(s.substr(i));
            i=j+1;
        }
        for(auto s_each:myvec)
        {
            ret=max(ret,longestSubstring(s_each,k));
        }
        return ret;
    }

};