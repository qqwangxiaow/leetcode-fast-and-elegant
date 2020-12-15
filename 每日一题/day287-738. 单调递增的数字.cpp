//greedy
//1234321  1233999 一般情况
//2333332  2299999 特殊情况

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        int max=-1,idx=-1;
        for(int i=0;i<s.size()-1;++i){
            if(max<s[i]){
                max=s[i];
                idx=i;
            }
            if(s[i]>s[i+1]){
                s[idx]-=1;
                for(int j=idx+1;j<s.size();j++){
                    s[j]='9';
                }
                break;
            }
        }
        return stoi(s);
    }
};