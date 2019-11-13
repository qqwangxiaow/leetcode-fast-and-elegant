//slide window
/*1. Use two pointers: start and end to represent a window.
2. Move end to find a valid window.
3. When a valid window is found, move start to find a smaller window.*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mymap;
        for(int i=0;i<t.size();i++)
        {
            mymap[t[i]]++;
        }
        int head=0,begin=0,end=0,d=INT_MAX,count=t.size();
        while(end<s.size())
        {
            if(mymap[s[end]]>0)
            {
                count--; 
            }
            mymap[s[end]]--;
            end++;
            while(count==0)
            {
               if(end-begin<d)
               {
                   head=begin;
                   d=end-begin;
               }
               mymap[s[begin]]++;
               if(mymap[s[begin]]>0) 
               {
                   count++;
               }
               begin++;     
            }
        }
        
        return d==INT_MAX?"":s.substr(head,d);
    }
};