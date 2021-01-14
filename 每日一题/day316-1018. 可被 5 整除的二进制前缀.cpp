//% 5 or overflow
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>ret;
        long long count = 0;
        for(int i = 0; i < A.size(); ++i){
            count = count * 2 + A[i];
            count = count % 5;
            if (count % 5 == 0){
                ret.push_back(true);
            }
            else{
                ret.push_back(false);
            }   
        }
        return ret;
    }
};