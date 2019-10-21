//array
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count=0,line=1;
        for(int i=0;i<S.size();i++)
        {
            if(count+widths[S[i]-'a']>100)
            {
                line++;
                count=widths[S[i]-'a'];
            }
            else count+=widths[S[i]-'a'];
            
        }
        return {line,count};
    }
};