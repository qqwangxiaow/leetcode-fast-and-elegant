//stringstream
class Solution {
public:
    string toGoatLatin(string S) {
        stringstream iss(S),oss;
        string vowels("aeiouAEIOU"),ret,a,w;
        int count=1;
        while(iss>>w)
        {
            a.push_back('a');
            if(vowels.find_first_of(w[0])!=string::npos)
                oss <<' '<<w<<"ma"<< a;
            else
                oss <<' '<<w.substr(1)<<w[0]<<"ma"<<a;
        }
        return oss.str().substr(1);
    }
};