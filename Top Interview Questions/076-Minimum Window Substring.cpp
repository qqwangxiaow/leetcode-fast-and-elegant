//slide window
//distance=d not d+1 because end++ before
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mymap;
        for(int i=0;i<t.size();i++)
        {
            mymap[t[i]]++;
        }
        int begin=0,end=0,head=0,d=INT_MAX,count=t.size();
        while(end<s.size())
        {
            if(mymap[s[end]]>0)        //>0
            {
                count--;                
            }
            mymap[s[end]]--;           //move outsize
            end++;  
            while(count==0)
            {
                if(d>end-begin)
                {
                    d=end-begin;
                    head=begin;
                }
                mymap[s[begin]]++;     //move outside
                if(mymap[s[begin]]>0)  //not >=
                {
                    count++;
                }
                begin++;
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};