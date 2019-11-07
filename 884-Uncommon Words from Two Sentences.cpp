//istringstrem 
//如果只出现一次那么就是
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int>count;
        istringstream iss(A+" "+B);
        while(iss>>A)
        {
            count[A]++;
        }
        vector<string>ret;
        for(auto w:count)
        {
            if(w.second==1)
                ret.push_back(w.first);         
        }
        return ret;
    }
};