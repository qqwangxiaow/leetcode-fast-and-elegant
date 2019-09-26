//string find npos 
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
       string as=A;
        for(int rep=1;rep<=B.size()/A.size()+2;rep++,as+=A)
        {
            if(as.find(B)!=string::npos) return rep;
            
        }
        return -1;
    }
    
};
