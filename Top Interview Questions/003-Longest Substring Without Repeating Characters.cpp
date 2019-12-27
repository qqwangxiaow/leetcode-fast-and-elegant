//1.l can jump to correct index using map
//2.init l=-1 for ret=1 if s not empty
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret=0,l=-1;
        map<char,int>mymap;
        for(int i=0;i<s.size();i++)
        {
            if(mymap.count(s[i]))
            {
                l=max(l,mymap[s[i]]);
            }
            mymap[s[i]]=i;;
            ret=max(ret,i-l);
        }
        return ret; 
    }
};