//greedy find each alpha end
class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<int,26>myarray;
        vector<int>ret;
        for(int i=0;i<S.size();i++)
        {
            myarray[S[i]-'a']=i;
        }
        int start=0,end=0;
        for(int i=0;i<S.size();i++)
        {
            end=max(end,myarray[S[i]-'a']);
            if(i==end)
            {
                ret.push_back(i-start+1);
                start=end+1;
            }
        }
        return ret;
    }
};