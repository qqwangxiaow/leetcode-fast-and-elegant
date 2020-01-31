//1.要用long
//2.用map保存循环的r 如果有循环的r相同的话 那么就又开始循环了
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator)
            return "0";
        string ret;
        if(numerator<0^denominator<0)
        {
            ret+="-";
        }
        long n=labs(numerator),d=labs(denominator),r=n%d;
        ret+=to_string(n/d);
        if(!r)
            return ret;
        ret+='.';
        unordered_map<long,int>mymap;
        while(r)
        {
            if(mymap.find(r)!=mymap.end())
            {
                ret.insert(mymap[r],"(");
                ret+=")";
                break;
            }
            mymap[r]=ret.size();
            r*=10;
            ret+=to_string(r/d);
            r=r%d;
        }
        return ret;
        
    }
};