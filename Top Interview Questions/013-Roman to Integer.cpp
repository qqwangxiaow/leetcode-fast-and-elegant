//map init {{},{},{}}
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mymap{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ret=mymap[s[s.size()-1]];
        for(int i=0;i<s.size()-1;i++)
        {
            if(mymap[s[i+1]]>mymap[s[i]])
            {
                ret-=mymap[s[i]];
                
            }
            else 
                ret+=mymap[s[i]];
        }
        return ret;
    }
};
