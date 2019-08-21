/*reverse*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i;
        for(i=2*k;i<s.size();i+=2*k)
        {
            reverse(s.begin()+i-2*k,s.begin()+i-k);

            
        }
        if(i-s.size()>k)
        {
            reverse(s.begin()+i-2*k,s.end());
        }
        else 
        {
            reverse(s.begin()+i-2*k,s.begin()+i-k);
        }
        return s;
        
    }
};

/*more concise*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0,j=k;
        while(j<s.size())
        {
            reverse(s.begin()+i,s.begin()+j);
            i+=2*k;
            j+=2*k;
        }
        if(i<s.size())
        {
            reverse(s.begin()+i,s.end());
        }
        return s;
        
        
    }
};

