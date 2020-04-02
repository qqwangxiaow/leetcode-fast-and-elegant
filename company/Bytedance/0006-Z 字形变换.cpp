//min(numRows, int(s.size()))
//addflag=false when init
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int len=s.size();
        vector<string>myvec(min(len,numRows),"");
        bool addflag=false;
        int toaddvector=0;
        for(auto c:s)
        {
            myvec[toaddvector]+=c;
            if(toaddvector==0||toaddvector==numRows-1)
                addflag=!addflag;
            toaddvector+=addflag?1:-1;
        }
        string ret;
        for(auto s:myvec)
        {
            ret+=s;
        }
        return ret;
    }
};