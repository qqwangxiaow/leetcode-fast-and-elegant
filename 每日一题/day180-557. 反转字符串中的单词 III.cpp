//注意最后一个位置
//reverse的end会多出一个位置
class Solution {
public:
    string reverseWords(string s) {
    int begin=0,end=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            end=i;
            reverse(s.begin()+begin,s.begin()+end);
            begin=i+1;
        }
        if(i==s.size()-1)
            reverse(s.begin()+begin,s.end());

    }
    return s;
}
};